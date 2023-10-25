 #include <fstream>

#include "Student.hpp"
#include "BackendGlobal.hpp"

using namespace Backend;

bool Student::createStudent(const std::string &studentID)
{
	if (g_students.find_if(
			[&studentID](const Student &student) -> bool
			{
				return student.getID() == studentID;
			})
		!= g_students.end())
	{
		return 0;
	}
	
	g_students.push_back(Student(studentID));
	g_accounts.push_back(static_cast<Account*>(&g_students.back()));
	return 1;
}

bool Student::deleteStudent(const std::string &studentID)
{
	auto currStudent = g_students.find_if(
		[&](const Student &student) -> bool
		{
			return student.getID() == studentID;
		});

	if (currStudent == g_students.end())
	{
		return 0;
	}

	currStudent->getClass()->removeStudent(&*currStudent);

	while (!currStudent->courseInfos().empty())
	{
		Course *course = currStudent->courseInfos().front().course;
		course->removeStudent(&*currStudent);
	}

	g_students.erase(currStudent);
	
	return 1;
}

Student::CourseInfo::CourseInfo(Course *nCourse, Course::StudentInfo *nStudentInfo)
{
	this->course = nCourse;
	this->studentInfo = nStudentInfo;
}

Student::Student()
	: Account(Account::Type::Student), class_(nullptr)
{
	password_ = "123456";
}

Student::Student(const std::string &nID)
	: Student()
{
	setID(nID);
}

const std::string& Student::getID() const
{
	return id_;
}

Class*& Student::getClass()
{
	return class_;
}

Class* const& Student::getClass() const
{
	return class_;
}

List<Student::CourseInfo>& Student::courseInfos()
{
	return courseInfos_;
}

const List<Student::CourseInfo>& Student::courseInfos() const
{
	return courseInfos_;
}

void Student::setID(const std::string &nID)
{
	id_ = nID;
	username_ = id_;
}
