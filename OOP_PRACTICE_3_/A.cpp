//
// Created by Nick Marhal on 1/30/18.
//


#include "A.h"

unsigned int A::_freeID = 0;

A &A::operator=(const A &source)
{
	//	this->_a = source._a; equal
	//	(*this)._a = source._a; equal
	_a = source._a;
	return *this;
}