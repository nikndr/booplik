//
// Created by Nick Marhal on 3/8/18.
//

#pragma once

#include "Date.h"
#include "Time.h"
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

class Timer
{
private:
	Date & _start_date;
	Time & _start_time;
	Time & _interval;

	void checkDateAndTime();

	bool validDateTime(Date & d, Time & t, tm * today);

public:
	Timer(Date & date, Time & time, Time & interval);

	Timer(Timer &);

	~Timer();

	Timer & operator=(const Timer &);

	void await();

	/*
	 * Avoids _start_date and _start_time and alerts only depending on interval
	 * passed as parameter
	 */
	static void alertIn(const Time &);

	Date start_date() const;

	Time start_time() const;

	Time interval() const;

	Date & start_date();

	Time & start_time();

	Time & interval();
};



