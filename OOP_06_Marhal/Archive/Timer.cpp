//
// Created by Nick Marhal on 3/8/18.
//

#include "Timer.h"

Timer::Timer(Date & date, Time & time, Time & interval) :
		_start_date(date), _start_time(time), _interval(interval)
{
	checkDateAndTime();
}


Timer::Timer(Timer & tr) :
		_start_date(tr.start_date()), _start_time(tr.start_time()), _interval(tr.interval())
{
	checkDateAndTime();
}

Timer::~Timer()
{

}

Timer & Timer::operator=(const Timer & tr)
{
	_start_time = tr.start_time();
	_start_date = tr.start_date();
	_interval = tr.interval();
	return *this;
}

void Timer::checkDateAndTime()
{
	auto * today = new tm;
	time_t timer;
	time(&timer);
	today = gmtime(&timer);

	if (!validDateTime(start_date(), start_time(), today)) {
		throw "Invalid date or time entered";
	}
}

bool Timer::validDateTime(Date & d, Time & t, tm * today)
{
	if (d.year() > today->tm_year+1900) {
		return true;
	} else if (d.year() < today->tm_year+1900) {
		return false;
	} else {
		if (d.month()-1 > today->tm_mon) {
			return true;
		} else if (d.month()-1 > today->tm_mon) {
			return false;
		} else {
			if (d.day() > today->tm_mday) {
				return true;
			} else if (d.day() < today->tm_mday) {
				return false;
			} else {//kjnknkjn
				if (t.hours() >= 24) {
					return false;
				}
				if (t.hours()-2 > today->tm_hour) {
					return true;
				} else if (t.hours()-2 < today->tm_hour) {
					return false;
				} else {
					if (t.minutes() > today->tm_min) {
						return true;
					} else if (t.minutes() < today->tm_min) {
						return false;
					} else {
						if (t.seconds() > today->tm_sec) {
							return true;
						}
					}
				}
				return false;
			}
		}
	}
	return false;
}

bool Timer::validTime(Time & t, struct tm * currTime)
{
	if (t.hours() >= 24) {
		return false;
	}
	if (t.hours()-2 > currTime->tm_hour) {
		return true;
	} else if (t.hours()-2 < currTime->tm_hour) {
		return false;
	} else {
		if (t.minutes() > currTime->tm_min) {
			return true;
		} else if (t.minutes() < currTime->tm_min) {
			return false;
		} else {
			if (t.seconds() > currTime->tm_sec) {
				return true;
			}
		}
	}
	return false;

}

Date Timer::start_date() const
{
	return _start_date;
}

Time Timer::start_time() const
{
	return _start_time;
}

Time Timer::interval() const
{
	return _interval;
}

Date & Timer::start_date()
{
	return _start_date;
}

Time & Timer::start_time()
{
	return _start_time;
}

Time & Timer::interval()
{
	return _interval;
}

void Timer::await()
{
	auto * td = new tm;
	time_t timer;
	time(&timer);
	td = gmtime(&timer);
	cout << "waiting until " << start_date() << " | " << start_time() << endl;

	while (td != start_date() || td != start_time()) {
		time(&timer);
		td = gmtime(&timer);
		this_thread::sleep_for(chrono::seconds(1));
		cout << td->tm_mday << "/" << td->tm_mon+1 << "/" << td->tm_year+1900 << " | " << td->tm_hour << ":"
		     << td->tm_min << ":" << td->tm_sec << endl;
	}

	cout << "The timer has started!" << endl;
	while (!_interval.zero()) {
		--_interval;
		cout << _interval << endl;
		this_thread::sleep_for(chrono::seconds(1));
	}
	cout << "\007" << "BEEP" << endl;
}

void Timer::alertIn(const Time & i)
{
	Time interval = i;
	cout << "The timer has started!" << endl;
	while (!interval.zero()) {
		cout << interval << endl;
		--interval;
		this_thread::sleep_for(chrono::seconds(1));
	}
	cout << "BEEP" << "\007" << endl;
}

