#include <fstream>
#include <filesystem>

#include "Class.hpp"
#include "Student.hpp"
#include "BackendGlobal.hpp"

using namespace Backend;

bool Class::loadClasses()
{
	std::filesystem::path path(CLASSES_PATH);

	if (!std::filesystem::exists(path))
	{
		std::filesystem::create_directories(path);
		return 0;
	}

	clearClasses();
	
	for (auto file: std::filesystem::directory_iterator(path))
	{
		g_classes.push_back(Class(toString(file.path().stem())));
		loadOneClass(file.path());
	}
	return 1;
}

void Class::loadOneClass(const std::filesystem::path &path)
{
	Class &currClass = g_classes.back();
	
	std::ifstream fi(path);
	std::string line;
	std::stringstream streamLine;
	while (!std::getline(fi, line))
	{
		streamLine.str(line);

		std::string no, studentID, firstName, lastName, gender, dateOfBirth, socialID;
		
		std::getline(streamLine, no);
		
		if (!std::getline(streamLine, studentID))
		{
			continue;
		}
		
		auto currStudent = g_students.find_if(
			[&](const Student &student)
			{
				return student.getID() == studentID;
			});

		if (currStudent == g_students.end())
		{
			g_students.push_back(Student(studentID));
		}
		currStudent = g_students.end()-1;

		std::getline(streamLine, firstName);
		currStudent->setFirstName(firstName);

		std::getline(streamLine, lastName);
		currStudent->setLastName(lastName);

		std::getline(streamLine, gender);
		currStudent->setGender(gender);

		std::getline(streamLine, dateOfBirth);
		currStudent->setDateOfBirth(dateOfBirth);

		std::getline(streamLine, socialID);
		currStudent->setSocialID(socialID);
	}
}

void Class::saveClasses()
{
	std::filesystem::path classesPath(CLASSES_PATH);
	for (auto directory: std::filesystem::directory_iterator(classesPath))
	{
		std::filesystem::remove_all(directory.path());
	}
	
	for (auto iClass = g_classes.begin(); iClass != g_classes.end(); ++iClass)
	{
		saveOneClass(&*iClass);
	}
}

void Class::saveOneClass(Class *currClass)
{
	std::filesystem::path path(CLASSES_PATH + currClass->getID() + ".csv");
	std::ofstream fo(path);
	
	int no = 0;
	for (auto iStudent = currClass->students().begin();
		 iStudent != currClass->students().end();
		 ++iStudent)
	{
		fo << ++no;
		fo << (*iStudent)->getID() << ',';
		fo << (*iStudent)->getFirstName() << ',';
		fo << (*iStudent)->getLastName() << ',';
		fo << Account::genderToString((*iStudent)->getGender()) << ',';
		fo << Account::dateToString((*iStudent)->getDateOfBirth()) << ',';
		fo << (*iStudent)->getSocialID() << '\n';
	}
}

void Class::clearClasses()
{
	while (!g_classes.empty())
	{
		Class::deleteClass(g_classes.front().getID());
	}
}

bool Class::createClass(const std::string &id)
{
	if (g_classes.find_if(
			[&](const Class &currClass) -> bool
			{
				return currClass.getID() == id;
			})
		!= g_classes.end())
	{
		return 0;
	}

	g_classes.push_back(Class(id));
	return 1;
}

bool Class::deleteClass(const std::string &id)
{
	auto currClass = g_classes.find_if(
		[&](const Class &class_) -> bool
		{
			return class_.getID() == id;
		});

	if (currClass == g_classes.end())
	{
		return 0;
	}
	
	while (!currClass->students().empty())
	{
		currClass->removeStudent(currClass->students().front());
	}

	g_classes.erase(currClass);
	
	return 1;
}

Class::Class()
{}

Class::Class(const std::string &nID)
{
	setID(nID);
}

const std::string& Class::getID() const
{
	return id_;
}

List<Student*>& Class::students()
{
	return students_;
}

const List<Student*>& Class::students() const
{
	return students_;
}

void Class::setID(const std::string &nID)
{
	id_ = nID;
}

bool Class::addStudent(Student *nStudent)
{
	if (students_.find(nStudent) == students_.end())
	{
		return 0;
	}
	
	students_.push_back(nStudent);
	nStudent->class_ = this;
	return 1;
}

bool Class::removeStudent(Student *student)
{
	auto currStudent = students_.find(student);

	if (currStudent == students_.end())
	{
		return 0;
	}

	student->class_ = nullptr;
	students_.erase(currStudent);

	return 1;
}
