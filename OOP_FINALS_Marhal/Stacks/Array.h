#pragma once

#include <iostream>
#include <string>

using namespace std;

template<class T>
class Array
{
public:

	class BadArray;

	explicit Array(size_t n) : _length(n), _allocator(new T[_length])
	{
		if (_allocator == nullptr)
			throw BadArray("BadAlloc array exception");
	}

	~Array()
	{
		delete[] _allocator;
	}

	T & operator[](const size_t index)
	{
		if (index >= _length)
			throw BadArray("Array out of bounds: ", index);
		return _allocator[index];
	}

	const T & operator[](const size_t index) const
	{
		if (index >= _length)
			throw BadArray("Array out of bounds: ", index);
		return _allocator[index];
	}

	size_t length() const
	{
		return _length;
	}

private:
	size_t _length;

	Array & operator=(const Array & a);

	Array(const Array &);

protected:
	T * const _allocator;
};

template<class T>
ostream & operator<<(ostream & os, const Array<T> & arr)
{
	os << "[";
	for (size_t i = 0; i < arr.length()-1; i++) {
		os << arr[i] << ", ";
	}
	os << arr[arr.length()-1] << "]";
	return os;
}

template<class T>
class Array<T>::BadArray
{
private:
	char * _message;
	size_t _index;
	bool show_indx;
public:
	BadArray(char * message) : _message(message), _index(0), show_indx(false)
	{
	}

	BadArray(char * message, size_t index) : _message(message), _index(index), show_indx(true)
	{
	}

	~BadArray()
	{
	}

	const char * getMessage() const
	{
		return _message;
	}

	void trace() const
	{
		cerr << _message;
		if (show_indx)
			cerr << _index;
		cerr << endl;
	}
};
