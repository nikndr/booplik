#include <cassert>
#include <iostream>
using namespace std;

#include "Array.h"

Array::Array (size_t sz):
	_size(sz),
	_pElem (new Elem[_size]),
	_pCurrent(_pElem),
	_pEnd(_pElem+_size)
{
	assert(_pElem != 0);
	return;
}

Array::~Array()
{
	delete [] _pElem;
}

Elem& Array::operator[] (size_t index)
{
	if (index<0 || index>=_size)
		throw BadArray();
	return _pElem[index];
}

const Elem& Array::operator[] (size_t index) const
{
	if (index<0 || index>=_size)
		throw BadArray();
	return _pElem[index];
}

size_t Array::size() const
{
	return _size;
}

ostream& operator<<(ostream &os, const Array& ar)
{
	char chr=' ';
	cout<<"Array of "<<ar.size();
	ar.start();
	while (!ar.finish())
	{
		cout<<chr<<ar.get();
		ar++;
		if (chr=' ') chr=',';
	}
	cout<<endl;
	return os;
}

