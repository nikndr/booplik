//
// Created by Nick Marhal on 4/17/18.
//

#include "Calendar.h"

const Date Calendar::nationalHolidays[11] =
		{
				Date(1, 1),
				Date(7, 1),
				Date(8, 3),
				Date(8, 4),
				Date(1, 5),
				Date(8, 5),
				Date(27, 5),
				Date(28, 6),
				Date(24, 8),
				Date(14, 10),
				Date(25, 12)
		};

const int Calendar::getWeekday() const
{
	struct tm * time = new tm;
	time->tm_mday = _date.day();
	time->tm_mon = _date.month()-1;
	time->tm_year = _date.year()-1900;
	mktime(time);
	return time->tm_wday;
}
