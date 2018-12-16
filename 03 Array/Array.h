#ifndef _ARRAY_
#define _ARRAY_

#include <iostream>
using namespace std;

typedef double Elem;
// Масив елементів типу Elem
class Array
{
public:
//	Клас для обробки помилкових ситуацій
	class BadArray{};
	explicit Array (size_t);
	~Array();

//	Модифікатор елементу масива
	Elem& operator[] (size_t index);
//	Селектор елементу масива
	const Elem& operator[] (size_t index) const;
//	Розмір масива (селектор)
	size_t size() const;
	void start() const {_pCurrent=_pElem;}
	bool finish() const { return _pCurrent == _pEnd;}
	const Array& operator++() const { _pCurrent++; return *this;}
//	const Array& operator++(int) const;
	const Elem& get() const { return *_pCurrent;}	

private:
	size_t _size;
	Elem * _pElem;
	mutable Elem * _pCurrent;
	Elem * _pEnd;

//	Операції і функції не визначені для масивів
	bool operator== (const Array&) const;
	Array(const Array&);
	Array& operator= (const Array&);
};

ostream& operator<<(ostream &, const Array&);

#endif