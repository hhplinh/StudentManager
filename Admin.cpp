#include <fstream>
#include <sstream>

#include "Admin.hpp"
#include "StaffMember.hpp"
#include "BackendGlobal.hpp"

using namespace Backend;

Admin::Admin()
	: Account(Account::Type::Admin)
{
	setUsername("admin");
}
