#include <iostream>
#include <cmath>
using namespace std;

#include "IndexedVarVector.h"

IndexedVarVector::IndexedVarVector(size_t len):
	_n(len),
	_v (new double[_n])
{
	fill(*this);
	return;
}

IndexedVarVector::IndexedVarVector
	(const IndexedVarVector& vec):
	_n(vec._n),
	_v (new double[vec._n])
{
	for (size_t i=0; i<_n; i++)
		_v[i] = vec._v[i];
	return;
}

IndexedVarVector& IndexedVarVector::operator=(const IndexedVarVector& vec)
{
	if (this==&vec)
		return *this;
	delete [] _v;
	_v = new double[_n];

	for (size_t i=0; i<_n; i++)
		_v[i] = vec._v[i];
	return *this;
}

IndexedVarVector::~IndexedVarVector()
{
	delete [] _v;
	return;
}

double IndexedVarVector::operator[](size_t i) const
{
	if ((i<0)||(_n<=i))
	{
		char * mes = "Bad index";
		throw mes;
	}
	return _v[i];
}

double& IndexedVarVector::operator[](size_t i)
{
	if ((i<0)||(_n<=i))
	{
		char * mes = "Bad index";
		throw mes;
	}
	return _v[i];
}

bool operator==(const IndexedVarVector&u, const IndexedVarVector& v)
{
	bool res = true;
	if (u.size() != v.size())
		return false;
	for (size_t i=0;i<u.size(); i++)
		res = res && (u[i]==v[i]);
	return res;
}
bool operator!=(const IndexedVarVector& u, const IndexedVarVector& v)
{
	return !(u == v);
};
double operator*(const IndexedVarVector& u, const IndexedVarVector& v)
{
	double res =0;
	for (size_t i=0;i<u.size(); i++)
		res += u[i]*v[i];
	return res;
}

const IndexedVarVector operator*(double x, const IndexedVarVector& u)
{
	IndexedVarVector res;
	for (size_t i=0;i<u.size(); i++)
		res[i]= x*u[i];
	return res;
}

const IndexedVarVector operator*(const IndexedVarVector& u, double x)
{
	IndexedVarVector res;
	for (size_t i=0;i<u.size(); i++)
		res[i]= u[i]*x;
	return res;
}

const IndexedVarVector operator+(const IndexedVarVector& u, const IndexedVarVector& v)
{
	IndexedVarVector res;
	for (size_t i=0;i<u.size(); i++)
		res[i] = u[i]+v[i];
	return res;
}

ostream& operator<<(ostream& os, const IndexedVarVector& u)
{
	char ch ='(';
	for (size_t i=0; i<u.size(); i++)
	{
		os<<ch<<u[i];
		ch =',';
	}
	os<<')'<<'('<<u.size()<<')'<<endl;

	return os;
}

void fill(IndexedVarVector& v)
{
	for (size_t i=0; i<v.size();++i)
		v[i] = rand();
	return;
}