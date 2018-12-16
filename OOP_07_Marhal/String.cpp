#include "String.h"

String::String() :
		_allocator(new char[1]), _len(0)
{
	_allocator[0] = '\0';
}

String::String(const char * ps)
{
	if (ps == 0) {
		throw BadString("Null string");
	}
	_len = strlen(ps);
	_allocator = new char[_len+1];
	strcpy(_allocator, ps);
}

String::String(const char c) :
		_len(1)
{
	_allocator = new char[2];
	_allocator[0] = c;
	_allocator[1] = '\0';
}

String::String(const string & s) :
		_allocator(new char[s.length()+1]),
		_len(s.length())
{
	strcpy(_allocator, s.c_str());
}

String::String(const String & s, int multiplayer) :
		_len(s._len*multiplayer), _allocator(new char[_len+1])
{
	char * target = _allocator;
	for (int i = 0; i < multiplayer; i++) {
		strcpy(target, s._allocator);
		target += s._len;
	}
};

String::~String()
{
	delete[] _allocator;
}

String & String::operator=(const String & s)
{
	if (this == &s) {
		return *this;
	}
	delete[] _allocator;
	_len = s.length();
	_allocator = new char[_len+1];
	strcpy(_allocator, s.c_str());
	return *this;
}

String & String::operator=(const string & s)
{
	*this = String(s);
	return *this;
}

String & String::operator=(const char * s)
{
	*this = String(s);
	return *this;
}

String & String::operator=(const char c)
{
	*this = String(c);
	return *this;
}

const string String::STL_string() const
{
	return string(c_str());
}

const char * String::c_str() const
{
	return _allocator;
}

size_t String::length() const
{
	return _len;
}

bool String::empty() const
{
	return _len == 0;
}

void String::clear()
{
	*this = String();
}

char & String::operator[](size_t i)
{
	if (i >= _len) {
		throw BadIndex("Out of bounds: ", i);
	}
	return _allocator[i];
}

const char String::operator[](size_t i) const
{
	if (i >= _len) {
		throw BadIndex("Out of bounds: ", i);
	}
	return _allocator[i];
}

bool String::operator==(const String & s) const
{
	bool equal = _len == s.length();
	for (size_t i = 0; (i < _len) && equal; i++) {
		equal = (_allocator[i] == s[i]);
	}
	return equal;
}

bool String::operator!=(const String & s) const
{
	return !(*this == s);
}

bool String::operator<(const String & s) const
{
	bool eq = true;
	size_t i = 0;
	while (eq && (i < _len) && (i < s._len)) {
		eq = eq && (_allocator[i] == s[i]);
		i++;
	}
	if (eq) {
		return _len < s.length();
	}
	i--;
	return _allocator[i] == s[i];
}

bool String::operator<=(const String & s) const
{
	if (*this == s) {
		return true;
	}
	return *this < s;
}

bool String::operator>(const String & s) const
{
	return !(*this <= s);
}

bool String::operator>=(const String & s) const
{
	if (*this == s) {
		return true;
	}
	return *this > s;
}

String String::operator+(const String & s) const
{
	String res(*this);
	return res += s;
}

String & String::operator+=(const char * ps)
{
	if (ps == 0) {
		return *this;
	}
	size_t len = strlen(ps);
	char * newAllocator = new char[len+_len+1];
	strcpy(newAllocator, _allocator);
	delete[] _allocator;
	_allocator = newAllocator;
	strcpy(_allocator+_len, ps);
	_len += len;
	return *this;
}

String & String::operator+=(const String & s)
{
	size_t len = _len+s.length();
	char * new_alloc = new char[len+1];
	strcpy(new_alloc, _allocator);
	delete[] _allocator;
	_allocator = new_alloc;
	strcpy(_allocator+_len, s._allocator);
	_len = len;
	return *this;
}

String & String::operator+=(const string & s)
{
	size_t len = _len+s.length();
	char * new_alloc = new char[len+1];
	strcpy(new_alloc, _allocator);
	delete[] _allocator;
	_allocator = new_alloc;
	strcpy(_allocator+_len, s.c_str());
	_len = len;
	return *this;
}

ostream & operator<<(ostream & out, const String & s)
{
	if (s.c_str() != 0) {
		return out << s.c_str();
	} else {
		return out << "0";
	}
}
