//
// Created by Nick Marhal on 3/7/18.
//

#pragma once

#include <iostream>

using namespace std;

class Time
{

private:

	int _hours;

	int _minutes;

	int _seconds;

//Функція службова, а тому закрита

	void normalizeTime();

public:

	explicit Time(int h = 0, int m = 0, int s = 0);

	Time(const Time &);

	~Time()
	{};

	Time & operator=(const Time &);

	explicit operator int() const;

	explicit operator double() const;

	bool zero() const;

	int hours() const;

	int minutes() const;

	int seconds() const;


	int & hours();

	int & minutes();

	int & seconds();


//Зміна часового проміжку на одну секунду

	const Time & operator++();

	const Time operator++(int);

	const Time & operator--();

	const Time operator--(int);

};

//Додавання часових проміжків

double operator+(const Time &, const Time &);

ostream & operator<<(ostream &, const Time &);

bool operator==(const Time & t1, const Time & t2);

bool operator!=(const Time & t1, const Time & t2);

bool operator==(const Time &, const struct tm *);

bool operator!=(const Time &, const struct tm *);

bool operator==(const struct tm *, const Time &);

bool operator!=(const struct tm *, const Time &);

