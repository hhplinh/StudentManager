#pragma once

struct Date
{
	int year, month, day;

	Date(int nYear = 0, int nMonth = 0, int nDay = 0);
	bool isValidDate();
};
