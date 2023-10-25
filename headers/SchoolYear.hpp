#pragma once

#include <string>
#include <filesystem>

#include "List.hpp"

namespace Backend
{
	class Semester;
	
	class SchoolYear
	{
	public:
		static bool loadSchoolYears();
		static void saveSchoolYears();
		static void clearSchoolYears();
		
		static bool createSchoolYear(int startYear);
	    static bool deleteSchoolYear(int startYear);
		
		SchoolYear();
		SchoolYear(int nStartYear);

		int getStartYear() const;

		List<Semester*>& semesters();
		const List<Semester*>& semesters() const;
		void setStartYear(int nStartYear);
		bool addSemester(Semester *nSemester);
		bool removeSemester(Semester *semester);

	private:
		int startYear_;
		List<Semester*> semesters_;
	};
}
