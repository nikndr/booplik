
#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

class Person;
class Position;
class Employer;

class Employee
{
friend class Employer;

private:
	const Person & _who;
	const Position & _what;
	Employee(const Person & who, const Position & what);
	Employee(const Employee&);
	~Employee();
	Employee& operator=(const Employee&);
public:
	const Person& who() const;
	const Position& what() const;
};

#endif