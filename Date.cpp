#include "Date.hpp"

Date::Date(int nYear, int nMonth, int nDay)
	: year(nYear), month(nMonth), day(nDay)
{}

bool Date::isValidDate()
{
	bool check = 1;
	if (month == 0 || month > 12)
		return false;
	bool leap = 0;
	if ((!(year % 4) && (year % 100)) ||
		!(year % 400))
		leap = 1;
	int *Tmp = new int[13];
	Tmp[1] = 31;
	Tmp[2] = ((leap) ? 29 : 28);
	Tmp[3] = 31;
	Tmp[4] = 30;
	Tmp[5] = 31;
	Tmp[6] = 30;
	Tmp[7] = 31;
	Tmp[8] = 31;
	Tmp[9] = 30;
	Tmp[10] = 31;
	Tmp[11] = 30;
	Tmp[12] = 31;
	if (day > Tmp[month] || day == 0)
		check = 0;
	delete[] Tmp;
	return check;
}
