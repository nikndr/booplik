//
// Created by Nick Marhal on 2/28/18.
//

#pragma once

#include <iostream>
#include <string>

using namespace std;

class Date
{

private:

	int _day, _month, _year;

	static bool leapYear(int y);

	void fillDate(int day, int month, int year);

	static void validateDate(int day, int month, int year);

	void validateChange();

	static void ensureDefault();

	static bool thirtyDays(int month);

	static bool thirtyOneDay(int month);

	static string monthNames[12];

	static bool defaultSet;

	static Date defaultDate;

public:

	class BadDate;

	explicit Date(int d = 1, int m = 1, int y = 1970);

	Date(const Date &);

	~Date();

	int day() const;

	int month() const;

	int year() const;

	const string getMonthName() const;

	void setDay(int);

	void setMonth(int);

	void setYear(int);


	static void setDefault(int, int, int);

	static void setDefault();

	static void showDefault();


	const Date & operator++();

	const Date operator++(int);

	const Date & operator--();

	const Date operator--(int);

};


ostream & operator<<(ostream & os, const Date & d);


class Date::BadDate
{

private:
	int _day, _month, _year;
public:
	BadDate(int d, int m, int y) : _day(d), _month(m), _year(y)
	{};

	string getMessage() const
	{
		return "Invalid date format:\nDay: "+to_string(_day)+"\nMonth: "+to_string(_month)+"\nYear: "+to_string(_year);
	}

};


ostream & operator<<(ostream & os, const Date::BadDate & bd);

bool operator==(const Date & d1, const Date & d2);

bool operator!=(const Date & d1, const Date & d2);

bool operator==(const struct tm * d1, const Date & d2);

bool operator!=(const struct tm * d1, const Date & d2);

bool operator==(const Date & d2, const struct tm * d1);

bool operator!=(const Date & d2, const struct tm * d1);
