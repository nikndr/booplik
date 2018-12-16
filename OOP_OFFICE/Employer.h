
#ifndef _EMPLOYER_H_
#define _EMPLOYER_H_

#include "Accountant.h"

class Person;
class Position;
class Employee;

class Employer
{
	friend void Accountant::payroll(const Employee &) const;
	friend void Accountant::payroll() const;
private:
	struct Staff
	{
		Employee * _pemployee;
		bool _free;
	};
	Accountant * _accountant;
	const Person & _me;

	int _volume;
	Staff * _office;

	Employer& operator=(const Employer&);
	Employer(const Employer&);

public:
	Employer(const Person & employer, const int volume, const Person & accountant);
	~Employer();
	const Accountant & myAccountant();
	void hire(const Person &, const Position &);
	void fire(const int);
	void pay() const;
};

#endif
