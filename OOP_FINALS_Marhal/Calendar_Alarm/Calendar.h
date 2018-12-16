//
// Created by Nick Marhal on 4/17/18.
//

#pragma once


#include "Date.h"

class Calendar
{
private:
	Date _date;
public:
	static const Date nationalHolidays[11];

	const int getWeekday() const;
};



