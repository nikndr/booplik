
#ifndef _POSITION_H
#define _POSITION_H
#include <string>
#include "Accountant.h"

class Position
{
friend void Accountant::payroll(const Employee&) const;
public:
	const string& getPositionName() const;
	explicit Position(char [], int);
	~Position();
private:
	string _name;
	int _salary;
	int getSalary() const;
};

#endif