
#ifndef _PERSON_H
#define _PERSON_H
#include <string>

class Person
{
public:
	const string& getName() const;
	explicit Person(const char []);
	Person(const Person&);
	~Person();
private:
	string _name;
	Person& operator=(const Person &);

};

#endif