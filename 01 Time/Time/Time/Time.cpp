#include "Time.h"

Time::Time (int s, int m, int h): _seconds(s), _minutes(m), _hours(h)
{
	normalizeTime();
}

void Time::normalizeTime()
{
	_minutes+=_seconds/60;
	_seconds%=60;
	_hours+=_minutes/60;
	_minutes%=60;
}

Time::operator int() const
{
	return _seconds+_minutes*60+_hours*3600;
}

ostream & operator<<(ostream & os, const Time & t)
{
	return os<<"H="<<t.hours()<<" M="<<t.minutes()<<" S="<<t.seconds();
}

const Time operator+(const Time & t1, const Time & t2)
{
	return Time(t1.operator int()+t2.operator int());
}