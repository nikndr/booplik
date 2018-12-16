
#include <iostream>
using namespace std;
#include "Person.h"

Person::Person(const char name[]): _name(name)
{	
	cout<<"A person "<<_name<<" was created"<<endl;
}

Person::Person(const Person& person)
{
	_name = person._name;
	cout<<"***Warning: You are copying a big object"<<endl;
	cout<<"***         This may cause inefficiency"<<endl;
	cout<<"A person "<<_name<<" was copied"<<endl;
	return;
}

Person::~Person()
{
	cout<<"A person "<<_name<<" was deleted"<<endl;
}

const string& Person::getName() const
{
	return _name;
}