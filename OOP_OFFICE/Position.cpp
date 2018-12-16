
#include <iostream>
using namespace std;
#include "Position.h"

Position::Position(char name[], int salary): _name(name), _salary(salary)
{	
	cout<<"A Position "<<_name<<'('<<_salary<<") was created"<<endl;
}

Position::~Position()
{
	cout<<"A Position "<<_name<<" was deleted"<<endl;
}

const string& Position::getPositionName() const
{
	return _name;
}

int Position::getSalary() const
{
	return _salary;
}