#pragma once

#include <string>

#include "Account.hpp"
#include "Course.hpp"
#include "List.hpp"

namespace Backend
{
	class StaffMember;
	class Class;
	class Course;
	
	class Student : public Account
	{
	public:
		struct CourseInfo
		{
			Course *course;
			Course::StudentInfo *studentInfo;

			CourseInfo(Course *nCourse = nullptr, Course::StudentInfo *nStudentInfo = nullptr);
		};
		
		static bool createStudent(const std::string &studentID);
	    static bool deleteStudent(const std::string &studentID);
		
		Student();
		Student(const std::string &nID);
		
		const std::string& getID() const;
		Class*& getClass();
		Class* const& getClass() const;
		List<CourseInfo>& courseInfos();
		const List<CourseInfo>& courseInfos() const;
		
		void setID(const std::string &nID);

	private:
		static void readCSV(std::stringstream &streamLine, std::string &word);
		
		std::string id_;
		Class *class_;
		List<CourseInfo> courseInfos_;

		friend StaffMember;
		friend class Class;
		friend class Course;
	};
}
