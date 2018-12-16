
#include <iostream>
using namespace std;
#include "Person.h"
#include "Position.h"
#include "Employer.h"
#include "Employee.h"
#include "Accountant.h"

Accountant::Accountant (const Employer & employer, const Person & accountant):
	 _myEmployer(employer), _who(accountant)
{
	cout<<"Accountant "<<_who.getName()<<" is hired"<<endl;
};

Accountant::~Accountant ()
{
	cout<<"Accountant was deleted"<<endl;
}

void Accountant::payroll() const
{
	cout<<"---Start payroll"<<endl;
	for (int i=0; i<_myEmployer._volume; i++)
		if (!_myEmployer._office[i]._free)
			payroll (*_myEmployer._office[i]._pemployee);
	cout<<"---Stop payroll"<<endl;
}

void Accountant::payroll(const Employee& employee) const
{
	cout<<"Pay "<<employee.who().getName()<<" amount "<<employee.what().getSalary()<<endl;
}
/*
Accountant& Accountant::operator=(const Accountant& p)
	{ 
		cout<<"c est moi"<<endl;
		return *this;
	}
*/
Accountant::Accountant(const Accountant& p):
	_myEmployer(p._myEmployer), _who(p._who)
{ 
		cout<<"c est moi copy"<<endl;
		return;
	}
