//
// Created by Nick Marhal on 4/15/18.
//
#pragma once

#include "Array.h"

//template<template <typename, typename> class Elem, class V, class A>
template<class Elem>
class Sequence
{
public:
	class BadSeq;

	explicit Sequence(const size_t capacity = _default);

	~Sequence();

	size_t capacity() const;

	size_t size() const;

	bool empty() const;

	bool full() const;

	Sequence & clear();

	const Elem & operator[](const size_t index) const;

	Elem & operator[](const size_t index);

	Sequence & append(const Elem & elem);

	Sequence & insert(const Elem & elem, const size_t index);

	Sequence & cut();

	Sequence & remove(const size_t index);

	bool contains(const Elem & elem);

private:
	static const size_t _default = 0;

	size_t _size;
	Array<Elem> * _allocator;


	Sequence & doinsert(const Elem & elem, const size_t index);

	Sequence & doremove(const size_t index);

	Sequence(const Sequence &);

	Sequence & operator=(const Sequence &);
};

template<class Elem>
ostream & operator<<(ostream & os, const Sequence<Elem> & seq)
{
	if (seq.empty())
		return os << "[]";

	os << "[";
	for (size_t i = 0; i < seq.size()-1; i++) {
		os << seq[i] << ", ";
	}
	os << seq[seq.size()-1] << "]";
	return os;
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

	const char * getMessage() const
	{
		return _message;
	}

	void print() const
	{
		cerr << _message << endl;
	}
};


// ------- Sequene realization ------- //

template<class Elem>
Sequence<Elem>::Sequence(const size_t capacity): _size(0), _allocator(new Array<Elem>(capacity))
{
	if (_allocator == nullptr)
		throw BadSeq("BadAlloc array exception");
}

template<class Elem>
Sequence<Elem>::~Sequence()
{
	delete _allocator;
}

template<class Elem>
size_t Sequence<Elem>::capacity() const
{
	return _allocator->length();
}

template<class Elem>
size_t Sequence<Elem>::size() const
{
	return _size;
}

template<class Elem>
bool Sequence<Elem>::empty() const
{
	return size() == 0;
}

template<class Elem>
bool Sequence<Elem>::full() const
{
	return capacity() == size();
}

template<class Elem>
Sequence<Elem> & Sequence<Elem>::clear()
{
	_size = 0;
	return *this;
}

template<class Elem>
Elem & Sequence<Elem>::operator[](const size_t index)
{
	if (empty())
		throw BadSeq("Sequence is empty");
	if (index >= size())
		throw BadSeq("Sequence is out of bounds");
	return (*_allocator)[index];
}

template<class Elem>
const Elem & Sequence<Elem>::operator[](const size_t index) const
{
	if (empty())
		throw BadSeq("Sequence is empty");
	if (index >= size())
		throw BadSeq("Sequence is out of bounds");
	return (*_allocator)[index];
}

template<class Elem>
Sequence<Elem> & Sequence<Elem>::append(const Elem & elem)
{
	return doinsert(elem, size());
}

template<class Elem>
Sequence<Elem> & Sequence<Elem>::insert(const Elem & elem, const size_t index)
{
	if (index > size())
		throw BadSeq("Can`t insert after non-existing element.");
	return doinsert(elem, index);
}

template<class Elem>
Sequence<Elem> & Sequence<Elem>::doinsert(const Elem & elem, const size_t index)
{
	_size++;

	for (size_t i = _size-1; i > index; i--) {
		(*_allocator)[i] = (*_allocator)[i-1];
	}
	(*_allocator)[index] = elem;
	return *this;
}

template<class Elem>
Sequence<Elem> & Sequence<Elem>::cut()
{
	return doremove(size()-1);
}

template<class Elem>
Sequence<Elem> & Sequence<Elem>::remove(const size_t index)
{
	if (index >= size())
		throw BadSeq("Can`t delete non-existing element.");
	return doremove(index);
}

template<class Elem>
Sequence<Elem> & Sequence<Elem>::doremove(const size_t index)
{
	--_size;
	for (size_t i = index; i < _size; i++) {
		(*_allocator)[i] = (*_allocator)[i+1];
	}
	return *this;
}


template<class Elem>
bool Sequence<Elem>::contains(const Elem & elem)
{
	for (size_t i = 0; i < size(); i++) {
		if ((*_allocator)[i] == elem)
			return true;
	}
	return false;
}

