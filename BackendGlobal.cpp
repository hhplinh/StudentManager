#include <codecvt>

#include "BackendGlobal.hpp"

using namespace Backend;

const std::string Backend::DATA_PATH = "../Data";
const std::string Backend::SCHOOL_YEARS_PATH = Backend::DATA_PATH + "/School Years";
const std::string Backend::CLASSES_PATH = Backend::DATA_PATH + "/Classes";
const std::string Backend::ACCOUNTS_PATH = Backend::DATA_PATH + "/accounts.csv";

Account *Backend::activeUser = nullptr;
SchoolYear *Backend::activeSchoolYear = nullptr;
Semester *Backend::activeSemester = nullptr;
Course *Backend::activeCourse = nullptr;
Class *Backend::activeClass = nullptr;

List<SchoolYear> Backend::g_schoolYears;
List<Semester> Backend::g_semesters;
List<Course> Backend::g_courses;
List<Class> Backend::g_classes;
List<Student> Backend::g_students;
List<StaffMember> Backend::g_staffMembers;
Admin Backend::g_admin;
List<Account*> Backend::g_accounts;

bool Backend::loadData()
{
	if (!Account::loadAccounts())
	{
		return 0;
	}

	if (!Class::loadClasses())
	{
		return 0;
	}
	
	if (!SchoolYear::loadSchoolYears())
	{
		return 0;
	}

	g_schoolYears.sort(
		[](const SchoolYear &s1, const SchoolYear &s2) -> bool
		{
			return s1.getStartYear() < s2.getStartYear();
		});
	g_semesters.sort(
		[](const Semester &s1, const Semester &s2) -> bool
		{
			int startYear1 = s1.schoolYear()->getStartYear();
			int startYear2 = s2.schoolYear()->getStartYear();
			return startYear1 < startYear2
				|| (startYear1 == startYear2 && s1.getID() < s2.getID());
		});
	setActiveSemester(&g_semesters.back());

	return 1;
}

void Backend::saveData()
{
	Account::saveAccounts(); 
	Class::saveClasses();
	SchoolYear::saveSchoolYears();
}

std::string Backend::toString(const std::wstring &wstring)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> convert;
	return convert.to_bytes(wstring);
}

void Backend::setActiveUser(Account *account)
{
	activeUser = account;
}

void Backend::setActiveSchoolYear(SchoolYear *schoolYear)
{
	activeSchoolYear = schoolYear;
}

void Backend::setActiveSemester(Semester *semester)
{
	activeSemester = semester;
	setActiveSchoolYear(semester->schoolYear());
}

void Backend::setActiveCourse(Course *course)
{
	activeCourse = course;
	setActiveSemester(course->semester());
}

void Backend::setActiveClass(Class *currClass)
{
	activeClass = currClass;
}
