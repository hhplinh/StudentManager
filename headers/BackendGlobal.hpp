#pragma once

#include <string>

#include "List.hpp"
#include "SchoolYear.hpp"
#include "Semester.hpp"
#include "Course.hpp"
#include "Class.hpp"
#include "Student.hpp"
#include "StaffMember.hpp"
#include "Admin.hpp"

namespace Backend
{
	class Account;
	
	extern const std::string DATA_PATH;
	extern const std::string SCHOOL_YEARS_PATH;
	extern const std::string CLASSES_PATH;
	extern const std::string ACCOUNTS_PATH;
	
	extern Account *activeUser;
	extern SchoolYear *activeSchoolYear;
	extern Semester *activeSemester;
	extern Course *activeCourse;
	extern Class *activeClass;
	
	extern List<SchoolYear> g_schoolYears;
	extern List<Semester> g_semesters;
	extern List<Course> g_courses;
	extern List<Class> g_classes;
	extern List<Student> g_students;
	extern List<StaffMember> g_staffMembers;
	extern Admin g_admin;
	extern List<Account*> g_accounts;

	bool loadData();
	void saveData();
	std::string toString(const std::wstring&);

	void setActiveUser(Account *account);
	void setActiveSchoolYear(SchoolYear *schoolYear);
	void setActiveSemester(Semester *semester);
	void setActiveCourse(Course *course);
	void setActiveClass(Class *currClass);
}
