#pragma once

#include "Account.hpp"

namespace Backend
{
	class StaffMember : public Account
	{
	public:
		static bool loadStaffMembers();

		static bool createStaffMember(const std::string &socialID);
		static bool deleteStaffMember(const std::string &socialID);
		
		StaffMember();
		StaffMember(const std::string &nSocialID);

		void setSocialID(const std::string &nSocialID) override;
		
	private:
		static void readCSV(std::stringstream &streamLine, std::string &word);
	};
}
