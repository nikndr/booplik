//
// Created by Nick Marhal on 3/7/18.
//

#include "Time.h"

void Time::normalizeTime()
{
	int s = static_cast<int>(*this);
	_hours = s/60/60;
	_minutes = s/60%60;
	_seconds = s%60;
}

Time::Time(int h, int m, int s) :
		_hours(h), _minutes(m), _seconds(s)
{
	normalizeTime();
}

Time::Time(const Time & t) :
		_seconds(t.seconds()), _minutes(t.minutes()), _hours(t.hours())
{
	//no need in calling `normalizeTime()` as `t` is already normalized
}

Time & Time::operator=(const Time & t)
{
	_seconds = t.seconds();
	_minutes = t.minutes();
	_hours = t.hours();
	return *this;
}

Time::operator int() const
{
	return _hours*3600+_minutes*60+_seconds;
}

Time::operator double() const
{
	double mins = _minutes+59./_seconds;
	double hrs = _hours+59./mins;
	return hrs;
}

int Time::hours() const
{
	return _hours;
}

int Time::minutes() const
{
	return _minutes;
}

int Time::seconds() const
{
	return _seconds;
}

int & Time::hours()
{
	normalizeTime();
	return _hours;
}

int & Time::minutes()
{
	normalizeTime();
	return _minutes;
}

int & Time::seconds()
{
	normalizeTime();
	return _seconds;
}

const Time & Time::operator++()
{
	++_seconds;
	normalizeTime();
	return *this;
}

const Time Time::operator++(int)
{
	Time temp = *this;
	++*this;
	return temp;
}

const Time & Time::operator--()
{
	--_seconds;
	normalizeTime();
	return *this;
}

const Time Time::operator--(int)
{
	Time temp = *this;
	--*this;
	return temp;
}

bool Time::zero() const
{
	return _hours == 0 && _minutes == 0 & _seconds == 0;
}

double operator+(const Time & t1, const Time & t2)
{
	Time res = Time();
	res.seconds() = t1.seconds()+t2.seconds();
	res.minutes() = t1.minutes()+t2.minutes();
	res.hours() = t1.hours()+t2.hours();
	return static_cast<double> (res);
}

ostream & operator<<(ostream & out, const Time & t)
{
	return out << "Time: " << t.hours() << ":" << t.minutes() << ":" << t.seconds();
}

bool operator==(const Time & t1, const Time & t2)
{
	return t1.seconds() == t2.seconds() && t1.minutes() == t2.minutes() && t1.hours() == t2.hours();
}

bool operator!=(const Time & t1, const Time & t2)
{
	return !(t1 == t2);
}

bool operator==(const Time & t1, const struct tm * t2)
{
	return t1.hours() == t2->tm_hour+2 && t1.minutes() == t2->tm_min && t1.seconds() == t2->tm_sec;
}

bool operator!=(const Time & t1, const struct tm * t2)
{
	return !(t1 == t2);
}

bool operator==(const struct tm * t2, const Time & t1)
{
	return t1 == t2;
}

bool operator!=(const struct tm * t2, const Time & t1)
{
	return !(t1 == t2);
}
