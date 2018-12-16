//
// Created by Nick Marhal on 4/15/18.
//

#pragma once

#include <iostream>
#include "Array.h"

using namespace std;

template<class T>
class Sequence
{
public:
	class BadSeq;

	explicit Sequence(size_t capacity = _default);

	~Sequence();

	size_t capacity() const;

	size_t size() const;

	bool empty() const;

	bool full() const;

	Sequence & clear();

	const T & operator[](size_t index) const;

	T & operator[](size_t index);

	Sequence & add(const T & elem);

	Sequence & insert(const T & elem, size_t index);

	Sequence & cut();

	Sequence & remove(size_t index);

	bool contains(const T & elem);

private:
	size_t _size;
	static const size_t _default;
	Array<T> * _allocator;

	void resize();

	Sequence & doinsert(const T & elem, size_t index);

	Sequence & doremove(size_t index);

	Sequence(const Sequence &);

	Sequence & operator=(const Sequence &);
};

template<class T>
ostream & operator<<(ostream & out, Sequence<T> & s);


template<class T>
const size_t Sequence<T>::_default = 10;

template<class T>
Sequence<T>::Sequence(const size_t capacity) :
		_size(0), _allocator(new Array<T>(capacity))
{

}

template<class T>
Sequence<T>::~Sequence()
{
	delete _allocator;
}

template<class T>
size_t Sequence<T>::capacity() const
{
	return _allocator->length();
}

template<class T>
size_t Sequence<T>::size() const
{
	return _size;
}

template<class T>
bool Sequence<T>::empty() const
{
	return _size == 0;
}

template<class T>
bool Sequence<T>::full() const
{
	return _size == _allocator->length();
}

template<class T>
Sequence<T> & Sequence<T>::clear()
{
	_size = 0;
	return *this;
}

template<class T>
const T & Sequence<T>::operator[](const size_t index) const
{
	if (index < _size) {
		return _allocator[index];
	} else {
		throw Sequence<T>::BadSeq("Bad index");
	}
}

template<class T>
T & Sequence<T>::operator[](const size_t index)
{
	if (index < _size) {
		return (*_allocator)[index];
	} else {
		throw Sequence<T>::BadSeq("Bad index");
	}
}

template<class T>
Sequence<T> & Sequence<T>::add(const T & elem)
{
	return doinsert(elem, _size);
}

template<class T>
Sequence<T> & Sequence<T>::insert(const T & elem, const size_t index)
{
	if (index < _size) {
		return doinsert(elem, index);
	} else {
		throw Sequence<T>::BadSeq("Bad index");
	}
}

template<class T>
Sequence<T> & Sequence<T>::cut()
{
	cout << "cut " << _size << endl;
	return doremove(_size);
}

template<class T>
Sequence<T> & Sequence<T>::remove(size_t index)
{
	if (index < _size) {
		doremove(index);
	} else {
		throw Sequence<T>::BadSeq("Bad index");
	}
	return *this;
}

template<class T>
bool Sequence<T>::contains(const T & elem)
{
	for (size_t i = 0; i < _size; i++) {
		if (elem == (*_allocator)[i]) {
			return true;
		}
	}
	return false;
}

template<class T>
void Sequence<T>::resize()
{
	if (_size+1 >= _allocator->length()) {
		Array * new_alloc = new Array<T>(_size*2+1);
		for (size_t i = 0; i < _allocator->length(); i++) {
			(*new_alloc)[i] = (*_allocator)[i];
		}
		delete _allocator;
		_allocator = new_alloc;
	} else if (_size <= _allocator->length()/4) {
		Array * new_alloc = new Array<T>(_size/2+1);
		for (size_t i = 0; i < new_alloc->length(); i++) {
			(*new_alloc)[i] = (*_allocator)[i];
		}
		delete _allocator;
		_allocator = new_alloc;
	}
}

template<class T>
Sequence<T> & Sequence<T>::doinsert(const T & elem, const size_t index)
{
	resize();
	for (size_t i = _size; i > index; --i) {
		(*_allocator)[i] = (*_allocator)[i-1];
	}
	(*_allocator)[_size++] = elem;
	return *this;
}

template<class T>
Sequence<T> & Sequence<T>::doremove(const size_t index)
{

	if (!empty()) {
		resize();
		for (size_t i = index; i < _size-1; i++) {
			(*_allocator)[i] = (*_allocator)[i+1];
		}
		_size--;
	} else {
		throw Sequence<T>::BadSeq("Empty sequence");
	}
	return *this;
}


template<class T>
ostream & operator<<(ostream & out, Sequence<T> & s)
{
	out << "(";
	for (size_t i = 0; i < s.size(); i++) {
		out << s[i] << (i != s.size()-1 ? "," : ")");
	}
	return out;
}

template<class T>
class Sequence<T>::BadSeq
{
private:
	char * _message;
public:
	BadSeq(char * message) : _message(message)
	{
	}

	~BadSeq()
	{
	}

	void printStackTrace() const
	{
		cout << _message << endl;
	}
};