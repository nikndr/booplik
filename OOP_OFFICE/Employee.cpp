
#include <iostream>
using namespace std;
#include "Person.h"
#include "Position.h"
#include "Employee.h"
 
Employee::Employee(const Person & who, const Position & what):_who(who),_what(what)
{
	cout<<"Employee "<<_who.getName()<<" takes a position "<<_what.getPositionName()<<endl;
};

Employee::~Employee()
{
	cout<<"Employee "<<_who.getName()<<" fired from "<<_what.getPositionName()<<endl;
};

const Person& Employee::who() const
{
	return _who;
}
const Position& Employee::what() const
{
	return _what;
}