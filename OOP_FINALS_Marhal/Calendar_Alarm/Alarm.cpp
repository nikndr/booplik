//
// Created by Nick Marhal on 3/8/18.
//

#include "Alarm.h"

Alarm::Alarm(Date & date, Time & time, bool skipHolidays) :
		_date(date), _time(time), _canceled(false),
		_skipHolidays(skipHolidays)
{
	checkDateAndTime();
}


Alarm::Alarm(Alarm & tr) :
		_date(tr.start_date()), _time(tr.start_time())
{
	checkDateAndTime();
}

Alarm::~Alarm()
{

}

Alarm & Alarm::operator=(const Alarm & tr)
{
	_time = tr.start_time();
	_date = tr.start_date();
	return *this;
}

void Alarm::checkDateAndTime()
{
	auto * today = new tm;
	time_t timer;
	time(&timer);
	today = gmtime(&timer);

	if (!validDateTime(start_date(), start_time(), today)) {
		throw "Invalid date or time entered";
	}
}

bool Alarm::validDateTime(Date & d, Time & t, tm * today)
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
}

Date Alarm::start_date() const
{
	return _date;
}

Time Alarm::start_time() const
{
	return _time;
}

Date & Alarm::start_date()
{
	return _date;
}

Time & Alarm::start_time()
{
	return _time;
}

bool Alarm::is_holiday() const
{
	for (size_t i = 0; i < 11; i++) {
		if (Calendar::nationalHolidays[i] == _date) {
			return true;
		}
	}
	return false;
}

void Alarm::simulate()
{
	wait_until_start();
	while (!_canceled) {
		if (_skipHolidays && is_holiday()) {
			cout << "holiday!" << endl;
			return;
		}
		ring();
		cout << "waiting 5 seconds to ring" << endl;
		this_thread::sleep_for(chrono::seconds(5));
	}
}

void Alarm::wait_until_start()
{
	struct tm * td;
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
}

void Alarm::ring()
{
	cout << "hold space to cancel alarm" << endl;
	for (int i = 0; i < 5; i++) {
		cout << "DING!" << "\007" << endl;
		this_thread::sleep_for(chrono::seconds(1));
		checkForCancel();
	}
}

void Alarm::checkForCancel()
{
//	if (GetKeyState(VK_SPACE) & (1 << 15)) {
	_canceled = true;
//	}
}

void Alarm::alertIn(const Time & i)
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
