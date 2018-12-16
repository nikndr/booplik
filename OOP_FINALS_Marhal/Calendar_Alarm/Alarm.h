//
// Created by Nick Marhal on 3/8/18.
//

#pragma once

#include "Date.h"
#include "time.h"
#include "Calendar.h"
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

class Alarm
{
private:
	Date & _date;
	Time & _time;
	bool _canceled;
	bool _skipHolidays;

	void checkDateAndTime();

	bool validDateTime(Date & d, Time & t, tm * today);

	void ring();

	void checkForCancel();

	bool is_holiday() const;

public:
	Alarm(Date & date, Time & time, bool skipHolidays);

	Alarm(Alarm &);

	~Alarm();

	Alarm & operator=(const Alarm &);

	void wait_until_start();

	/*
	 * Avoids _start_date and _start_time and alerts only depending on interval
	 * passed as parameter
	 */
	static void alertIn(const Time &);

	Date start_date() const;

	Time start_time() const;


	Date & start_date();

	Time & start_time();


	void simulate();

};



