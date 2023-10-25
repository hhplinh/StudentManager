#pragma once

#include <filesystem>

#include "List.hpp"

namespace Backend
{
	class SchoolYear;
	class Course;

	class Semester
	{
	public:
		Semester();
		Semester(int nID, SchoolYear *schoolYear);

		static bool loadSemesters(const std::filesystem::path &path, SchoolYear *schoolYear);
		static void saveSemesters(const std::filesystem::path &path, SchoolYear *schoolYear);
		static void clearSemesters(SchoolYear *schoolYear);
		
		static bool createSemester(int id, int schoolYear);
	    static bool deleteSemester(int id, int schoolYear);
		
		int getID() const;
		SchoolYear*& schoolYear();
		SchoolYear* const& schoolYear() const;
		List<Course*>& courses();
		const List<Course*>& courses() const;
		/* const std::string& getPath() const; */

		void setID(int nID);
		bool addCourse(Course *nCourse);
		bool removeCourse(Course *course);
		
	private:
		int id_;
		SchoolYear *schoolYear_;
		List<Course*> courses_;
		/* std::filesystem::path path_; */
		
		friend class SchoolYear;
	};
}
