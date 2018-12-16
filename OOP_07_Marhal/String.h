#pragma once

#include <string>
#include <iostream>

using namespace std;

class String
{

private:

	size_t _len;

	char * _allocator;

public:

	class BadString;

	class BadIndex;

	String();

	explicit String(const char *);

	explicit String(char);

	explicit String(const string &);

	String(const String & s, int multiplayer = 1);


	~String();


	String & operator=(const String &);

	String & operator=(const string &);

	String & operator=(const char *);

	String & operator=(char);


	const string STL_string() const;

	const char * c_str() const;

	size_t length() const;


	bool empty() const;

	void clear();


	char & operator[](size_t);

	const char operator[](size_t) const;


	bool operator==(const String &) const;

	bool operator!=(const String &) const;

	bool operator<(const String &) const;

	bool operator<=(const String &) const;

	bool operator>(const String &) const;

	bool operator>=(const String &) const;


	String operator+(const String &) const;

	String & operator+=(const char *);

	String & operator+=(const String &);

	String & operator+=(const string &);

};

ostream & operator<<(ostream &, const String &);

class String::BadString
{
private:

	string _reason;
public:
	explicit BadString(string reason = "") :
			_reason(reason)
	{

	};

	~BadString()
	{};

	void message() const
	{
		cerr << _reason << endl;
	}
};

class String::BadIndex
{
	string _reason;

	size_t _index;

public:
	BadIndex(string reason = "", size_t index = 0) :
			_reason(reason), _index(index)
	{

	};

	~BadIndex()
	{};

	void message() const
	{
		cerr << _reason << endl << " " << _index << endl;
	};
};
