//
// Created by Nick Marhal on 2/28/18.
//

#include "Date.h"
#include <ctime>

string Date::monthNames[] = {"January", "February", "March", "April", "May", "June", "July", "August",
                             "September",
                             "October", "November", "December"};

bool Date::defaultSet = false;

Date Date::defaultDate = Date();

Date::Date(int d, int m, int y)
{
	fillDate(d, m, y);
}

Date::Date(const Date &date)
{
	fillDate(date.day(), date.month(), date.year());
}

Date::~Date()
{

}

void Date::setDefault()
{
	auto *today = new tm;
	time_t timer;
	time(&timer);
	today = gmtime(&timer);
	defaultDate._day = today->tm_mday;
	defaultDate._month = today->tm_mon;
	defaultDate._year = today->tm_year += 1900;
}

void Date::setDefault(int day, int month, int year)
{
	validateDate(day, month, year);
	defaultDate._day = day;
	defaultDate._month = month;
	defaultDate._year = year;
}


void Date::showDefault()
{
	ensureDefault();
	cout << defaultDate << endl;
}

void Date::ensureDefault()
{
	if (!defaultSet) {
		defaultSet = true;
		setDefault();
	}
}

void Date::fillDate(int day, int month, int year)
{
	ensureDefault();
	validateDate(day, month, year);
	_day = day;
	_month = month;
	_year = year;
}

bool Date::thirtyDays(int month)
{
	return month == 4 || month == 6 || month == 9 || month == 11;
}


bool Date::thirtyOneDay(int month)
{
	return month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12;
}

void Date::validateDate(int day, int month, int year)
{
	if (day > 0) {
		if (month == 2) {
			if (!leapYear(year) && day > 28) {
				throw BadDate(day, month, year);
			} else if (leapYear(year) && day > 29) {
				throw BadDate(day, month, year);
			}
		} else if (thirtyDays(month) && day > 30) {
			throw BadDate(day, month, year);
		} else if (thirtyOneDay(month) && day > 31) {
			throw BadDate(day, month, year);
		} else if (month < 0 || month > 12) {
			throw BadDate(day, month, year);
		}
	} else {
		throw BadDate(day, month, year);
	}
}

void Date::validateChange()
{
	if (_day < 1) {
		_month--;
		if (_month == 2) {
			if (leapYear(_year)) {
				_day = 29;
			} else {
				_day = 28;
			}
		} else if (thirtyDays(_month)) {
			_day = 30;
		} else {
			_day = 31;
		}
	} else if ((_day > 31 && thirtyOneDay(_month)) || (_day > 30 && thirtyDays(_month))) {
		_month++;
		_day = 1;
	} else if (_month == 2) {
		if (leapYear(_year) && _day > 29) {
			_month++;
			_day = 1;
		} else {
			if (_day > 28) {
				_month++;
				_day = 1;
			}
		}
	}
	if (_month > 12) {
		_month = 1;
		_year++;
	}
	if (_month < 1) {
		_month = 12;
		_year--;
	}
}

bool Date::leapYear(int y)
{
	bool leap;
	if (y%4) {
		leap = false;
	} else if (y%100) {
		leap = true;
	} else if (y%400) {
		leap = false;
	} else leap = true;
	return leap;
}

int Date::day() const
{
	return _day;
}

int Date::month() const
{
	return _month;
}

int Date::year() const
{
	return _year;
}

//TODO probably
const string Date::getMonthName() const
{
	return monthNames[_month-1];
}

void Date::setDay(int day)
{
	validateDate(day, _month, _year);
	_day = day;
}

void Date::setMonth(int month)
{
	validateDate(_day, month, _year);
	_month = month;
}

void Date::setYear(int year)
{
	validateDate(_day, _month, year);
	_year = year;
}


const Date &Date::operator++()
{
	++_day;
	validateChange();
	return *this;
}

const Date Date::operator++(int)
{
	Date temp = *this;
	++*this;
	return temp;
}

const Date &Date::operator--()
{
	--_day;
	validateChange();
	return *this;
}

const Date Date::operator--(int)
{
	Date temp = *this;
	--*this;
	return temp;
}

ostream &operator<<(ostream &os, const Date &d)
{
	return os << d.day() << "/" << d.month() << "/" << d.year();
}

ostream &operator<<(ostream &os, const Date::BadDate &bd)
{
	return os << bd.getMessage();
}
