//
// Created by Nick Marhal on 3/9/18.
//

#include "DateTime.h"

DateTime::DateTime(Date & date, Time & time) :
		_date(date), _time(time)
{

}

DateTime::DateTime(const DateTime & dt) :
		_date(dt.date()), _time(dt.time())
{

}

DateTime::~DateTime()
{

}

DateTime & DateTime::operator=(const DateTime & dt)
{
	date() = dt.date();
	time() = dt.time();
	return *this;
}

Date & DateTime::date() const
{
	return _date;
}

Time & DateTime::time() const
{
	return _time;
}

Date & DateTime::date()
{
	return _date;
}

Time & DateTime::time()
{
	return _time;
}

bool operator==(const DateTime & dt, const struct tm * sdt)
{
	return sdt->tm_mday == dt.date().day() && sdt->tm_mon+1 == dt.date().month() &&
	       (sdt->tm_year+1900 == dt.date().year());
}
