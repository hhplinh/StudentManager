#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "StaffMember.hpp"
#include "Student.hpp"
#include "BackendGlobal.hpp"

using namespace Backend;

bool StaffMember::loadStaffMembers()
{
	std::ifstream fi;
	fi.open(ACCOUNTS_PATH + "/staff members.csv");

	if (!fi.is_open())
	{
		return 0;
	}

	std::string line;
	std::stringstream streamLine;
	while (std::getline(fi, line))
	{
		streamLine.str(line);
		
		std::string no, firstName, lastName, gender, dateOfBirth, socialID;
		readCSV(streamLine, no);
		readCSV(streamLine, firstName);
		readCSV(streamLine, lastName);
		readCSV(streamLine, gender);
		readCSV(streamLine, dateOfBirth);
		readCSV(streamLine, socialID);
		
		g_staffMembers.push_back(StaffMember(socialID));
		StaffMember &currStaffMember = g_staffMembers.back();
		g_accounts.push_back(&currStaffMember);
		currStaffMember.setFirstName(firstName);
		currStaffMember.setLastName(lastName);
		currStaffMember.setGender(gender);
		currStaffMember.setDateOfBirth(dateOfBirth);
	}

	return 1;
}

void StaffMember::readCSV(std::stringstream &streamLine, std::string &word)
{
	std::string tmp;
	if (std::getline(streamLine, tmp, ','))
	{
		word = tmp;
	}
}

bool StaffMember::createStaffMember(const std::string &socialID)
{
	if (g_staffMembers.find_if(
			[&](const StaffMember &staffMember) -> bool
			{
				return socialID == staffMember.getSocialID();
			})
		!= g_staffMembers.end())
	{
		return 0;
	}
	
	g_staffMembers.push_back(StaffMember(socialID));
	g_accounts.push_back(static_cast<Account*>(&g_staffMembers.back()));
	return 1;
}

bool StaffMember::deleteStaffMember(const std::string &socialID)
{
	return g_staffMembers.remove_if(
		[&](const StaffMember &staffMember) -> bool
		{
			return staffMember.getSocialID() == socialID;
		});
}

StaffMember::StaffMember()
	: Account(Type::StaffMember)
{}

StaffMember::StaffMember(const std::string &nSocialID)
	: StaffMember()
{
	setSocialID(nSocialID);
}

void StaffMember::setSocialID(const std::string &nSocialID)
{
	socialID_ = nSocialID;
	username_ = socialID_;
}
