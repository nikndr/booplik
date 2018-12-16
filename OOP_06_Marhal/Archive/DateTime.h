//
// Created by Nick Marhal on 3/9/18.
//

#pragma once


#include "Date.h"
#include "Time.h"

class DateTime
{
private:
	Date & _date;
	Time & _time;

public:
	explicit DateTime(Date & date, Time & time);

	DateTime(const DateTime &);

	~DateTime();

	DateTime & operator=(const DateTime &);

	Date & date() const;

	Time & time() const;

	Date & date();

	Time & time();
};

bool operator==(const DateTime &, const struct tm *);

bool operator!=(const DateTime &, const struct tm *);

bool operator==(const struct tm *, const DateTime &);

bool operator!=(const struct tm *, const DateTime &);
