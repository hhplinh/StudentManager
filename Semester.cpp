#include <filesystem>

#include "Semester.hpp"
#include "Course.hpp"
#include "BackendGlobal.hpp"

using namespace Backend;

bool Semester::loadSemesters(const std::filesystem::path &path, SchoolYear *schoolYear)
{
	if (!std::filesystem::exists(path))
	{
		return 0;
	}

	clearSemesters(schoolYear);
	
	for (auto semesterPath: std::filesystem::directory_iterator(path))
	{
		int id = std::stoi(semesterPath.path().filename());
		g_semesters.push_back(Semester(id, schoolYear));
		Course::loadCourses(semesterPath.path(), &g_semesters.back());
	}
	return 1;
}

void Semester::saveSemesters(const std::filesystem::path &path, SchoolYear *schoolYear)
{
	if (!std::filesystem::exists(path))
	{
		std::filesystem::create_directories(path);
	}
	
	for (auto directory: std::filesystem::directory_iterator(path))
	{
		std::filesystem::remove_all(directory.path());
	}
	
	for (auto iSemester = schoolYear->semesters().begin();
		 iSemester != schoolYear->semesters().end();
		 ++iSemester)
	{
		std::filesystem::path currSemesterPath(path/std::to_string((*iSemester)->getID()));
		std::filesystem::create_directories(currSemesterPath);
		Course::saveCourses(currSemesterPath, *iSemester);
	}
}

void Semester::clearSemesters(SchoolYear *schoolYear)
{
	while (!schoolYear->semesters().empty())
	{
		Semester::deleteSemester(schoolYear->semesters().front()->getID(),
									schoolYear->getStartYear());
	}
}

bool Semester::createSemester(int id, int schoolStartYear)
{
	auto currSchoolYear = g_schoolYears.find_if(
		[&](const SchoolYear &schoolYear) -> bool
		{
			return schoolYear.getStartYear() == schoolStartYear;
		});

	if (currSchoolYear == g_schoolYears.end())
	{
		return 0;
	}
	
	g_semesters.push_back(Semester(id, &*currSchoolYear));
	currSchoolYear->addSemester(&g_semesters.back());
	return 1;
}

bool Semester::deleteSemester(int id, int schoolStartYear)
{
    auto currSemester = g_semesters.find_if(
		[&](const Semester &semester) -> bool
		{
			return semester.schoolYear()->getStartYear() == schoolStartYear
				&& semester.getID() == id;
		});

	if (currSemester == g_semesters.end())
	{
		return 0;
	}

    currSemester->schoolYear()->removeSemester(&*currSemester);

	while (!currSemester->courses().empty())
	{
		Course::deleteCourse(currSemester->courses().front()->getID());
	}
	
	g_semesters.erase(currSemester);

	return 1;
}

Semester::Semester()
	: schoolYear_(nullptr)
{}

Semester::Semester(int nID, SchoolYear *schoolYear)
	: Semester()
{
	setID(nID);
	/* directoryPath_ = schoolYear_->getDirectoryPath() + std::to_string(id_) + "/"; */
	schoolYear->addSemester(this);
}

int Semester::getID() const
{
	return id_;
}

SchoolYear*& Semester::schoolYear()
{
	return schoolYear_;
}

SchoolYear* const& Semester::schoolYear() const
{
	return schoolYear_;
}

List<Course*>& Semester::courses()
{
	return courses_;
}

const List<Course*>& Semester::courses() const
{
	return courses_;
}

/* const std::string& Semester::getPath() const
 * {
 * 	return path_;
 * } */

void Semester::setID(int nID)
{
	id_ = nID;
}

bool Semester::addCourse(Course *nCourse)
{
	if (courses_.find(nCourse) != courses_.end())
	{
		return 0;
	}
	
	courses_.push_back(nCourse);
	nCourse->semester() = this;
	/* nCourse->filePath_ = directoryPath_ + nCourse->getID() + ".csv"; */
	return 1;
}

bool Semester::removeCourse(Course *course)
{
	auto currCourse = courses().find(course);
	
	if (currCourse == courses().end())
	{
		return 0;
	}

	(*currCourse)->semester() = nullptr;
	courses().erase(currCourse);
	
	return 1;
}
