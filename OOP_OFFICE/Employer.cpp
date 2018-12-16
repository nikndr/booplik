
#include <iostream>
using namespace std;
#include "Person.h"
#include "Position.h"
#include "Employer.h"
#include "Employee.h"
#include "Accountant.h"



Employer::Employer(const Person & boss, const int volume, const Person & accountant):
	_me(boss),_volume(volume)
{
	cout<<"Employer "<<_me.getName()<<" with "<<_volume<<" positions was created"<<endl;
	_office = new Staff[_volume];
	for(int i=0; i< _volume; i++)
		_office[i]._free = true;

	_accountant = new Accountant(*this, accountant);
}

Employer::~Employer()
{
	cout<<"Employer "<<_me.getName()<<" with "<<_volume<<" positions was deleted"<<endl;
	delete [] _office;
	delete    _accountant;
}

void Employer::hire(const Person & person, const Position & position)
{
	Employee * pemployee = new Employee (person, position);
	int i=0;
	while ((i<_volume) && (!_office[i]._free))
		 i++;
	_office[i]._free = false;
	_office[i]._pemployee = pemployee;
};
void Employer::fire(const int i)
{
//	to be developed
};

void Employer::pay() const
{
	_accountant->payroll();
}

const Accountant & Employer::myAccountant()
{
	return *_accountant;
}
