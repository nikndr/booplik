//
// Created by Nick Marhal on 3/31/18.
//

#pragma once

#include <iostream>

using namespace std;

template<size_t n, class T>
class Array
{
private:
	T * _alloc;

	size_t _length;

public:
	class BadArray;

	explicit Array() :
			_length(n)
	{
		_alloc = new T[_length]();
	}

	Array(const Array & source) :
			_length(source.length())
	{
		delete[] _alloc;
		_alloc = nullptr;
		_alloc = new T[_length]();
		for (size_t i = 0; i < _length; i++) {
			_alloc[i] = source[i];
		}
	}

	~Array()
	{
		delete[] _alloc;
		_alloc = nullptr;
	}

	Array & operator=(const Array & source)
	{
		delete[] _alloc;
		_alloc = nullptr;
		_alloc = new T[source.length()]();
		for (size_t i = 0; i < source.length(); i++) {
			_alloc[i] = source[i];
		}
		return *this;
	}

	const T & operator[](const size_t ind) const
	{
		if (ind < _length) {
			return _alloc[ind];
		}
		throw BadArray("Index out of bounds: ", ind);
	}

	T & operator[](const size_t ind)
	{
		if (ind < _length) {
			return _alloc[ind];
		}
		throw BadArray("Index out of bounds: ", ind);
	}

	const size_t length() const
	{
		return _length;
	}

};

template<size_t n, class T>
class Array<n, T>::BadArray
{
private:
	const char * _msg;
	size_t _ind;
public:
	BadArray(const char * msg, const size_t ind) :
			_msg(msg), _ind(ind)
	{

	}

	~BadArray()
	{}

	void trace() const
	{
		cerr << "In Array of size: " << n << "\nType: " << typeid(T).name() << "\nMessage: "  << _msg << "\nIndex: " << _ind << endl;
	}

	const char * get_message() const
	{
		return _msg;
	}

	const size_t get_index() const
	{
		return _ind;
	}

};


template<size_t n, class T>
ostream & operator<<(ostream & out, const Array<n, T> & arr)
{
	out << &arr << endl << "[";
	for (size_t i = 0; i < arr.length(); i++) {
		out << arr[i] << (i+1 == arr.length() ? "" : ", ");
	}
	return out << "]";
};
