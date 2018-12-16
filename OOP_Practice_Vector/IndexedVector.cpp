#include <iostream>
#include <cmath>
using namespace std;

#include "IndexedVector.h"

const size_t IndexedWrappedVector::_n = 5;

IndexedWrappedVector::IndexedWrappedVector():
	_v (new double[_n])
{	
	fill(*this);
}

IndexedWrappedVector::IndexedWrappedVector(const IndexedWrappedVector& vec):
	_v (new double[_n])
{	
	for (size_t i=0; i<_n; i++)
		_v[i] = vec._v[i];
	return;
}

IndexedWrappedVector::~IndexedWrappedVector()
{
	delete [] _v;
	_v = 0;
	return;
}

IndexedWrappedVector& IndexedWrappedVector::operator=(const IndexedWrappedVector& vec)
{
	for (size_t i=0; i<_n; i++)
		_v[i] = vec._v[i];
	return *this;
}

double IndexedWrappedVector::operator[](size_t i) const
{
	if (_n<=i)
	{
		char * mes = "Bad index";
		throw mes;
	}
	return _v[i];
}

double& IndexedWrappedVector::operator[](size_t i)
{
	if (_n<=i)
	{
		//char * mes = "Bad index";
		//throw mes;
		throw BadVector();
	}
	return _v[i];
}

bool operator==(const IndexedWrappedVector& u, const IndexedWrappedVector& v)
{
	bool res = true;
	for (size_t i=0;i<u.size(); i++)
		res = res && (u.operator[](i)==v.operator[](i));
		//res = res && (u[i]==v[i]);
	return res;
}

bool operator!=(const IndexedWrappedVector& u, const IndexedWrappedVector& v)
{
	return !(u == v);
}

double operator*(const IndexedWrappedVector& u, const IndexedWrappedVector& v)
{
	double res =0;
	for (size_t i=0;i<u.size(); i++)
		res += u[i]*v[i];
	return res;
}

const IndexedWrappedVector operator*(double x, const IndexedWrappedVector& u)
{
	IndexedWrappedVector res;
	for (size_t i=0;i<u.size(); i++)
		res[i]= x*u[i];
	return res;
}

const IndexedWrappedVector operator*(const IndexedWrappedVector& u, double x)
{
	IndexedWrappedVector res;
	for (size_t i=0;i<u.size(); i++)
		res[i]= u[i]*x;
	return res;
}

const IndexedWrappedVector operator+(const IndexedWrappedVector& u, const IndexedWrappedVector& v)
{
	IndexedWrappedVector res;
	for (size_t i=0;i<u.size(); i++)
		res[i] = u[i]+v[i];
	return res;
}

ostream& operator<<(ostream& os, const IndexedWrappedVector& u)
{
	char ch ='(';
	for (size_t i=0; i<u.size(); i++)
	{
		os<<ch<<u[i];
		ch =',';
	}
	os<<')'<<endl;

	return os;
}

void fill(IndexedWrappedVector& v)
{
	for (size_t i=0; i<v.size();++i)
		v[i] = rand();
	return;
}