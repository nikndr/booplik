
#ifndef _Accountant_H_
#define _Accountant_H_

class Employee;
class Employer;
class Person;

class Accountant
{
private:
	const Employer & _myEmployer;
	const Person & _who;
	Accountant& operator=(const Accountant&);

public:
	Accountant (const Employer & , const Person &);
	Accountant (const Accountant&);
	~Accountant ();
	void payroll() const;
	void payroll (const Employee &) const;
};

#endif
	