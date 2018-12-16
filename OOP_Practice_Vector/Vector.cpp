#include <iostream>
#include <cmath>

using namespace std;

#include "Vector.h"

const size_t WrappedVector::_n = 5;

WrappedVector::WrappedVector() :
		_v(new double[_n])
{
	fill();
	return;
}

WrappedVector::WrappedVector(const WrappedVector &vec) :
		_v(new double[_n])
{
	/*if (_v==0)
	{
		char * mes = "No more space in the system";
		throw mes;
	}*/
	for (size_t i = 0; i < _n; i++) {
		_v[i] = vec._v[i];
	}
	return;
}

WrappedVector &WrappedVector::operator=(const WrappedVector &vec)
{
	for (size_t i = 0; i < _n; i++) {
		_v[i] = vec._v[i];
	}
	return *this;
}

WrappedVector::~WrappedVector()
{
	delete[] _v;
	_v = 0;
	return;
}

bool WrappedVector::operator==(const WrappedVector &v) const
{
	bool res = true;
	for (size_t i = 0; i < size(); i++) {
		res = res && (_v[i] == v._v[i]);
	}
	return res;
}

bool WrappedVector::operator!=(const WrappedVector &v) const
{
	return !(*this == v);
}

double WrappedVector::operator*(const WrappedVector &v) const
{
	double res = 0;
	for (size_t i = 0; i < size(); i++) {
		res += _v[i]*v._v[i];
	}
	return res;
}

const WrappedVector WrappedVector::operator*(double x) const
{
	WrappedVector res;
	for (size_t i = 0; i < size(); i++) {
		res._v[i] = _v[i]*x;
	}
	return res;
}

const WrappedVector WrappedVector::operator+(const WrappedVector& v) const
{
	WrappedVector res;
	for (size_t i=0;i<size(); i++)
		res._v[i] = _v[i]+v._v[i];
	return res;
}

ostream &WrappedVector::show(ostream &os) const
{
	char ch = '(';
	for (size_t i = 0; i < size(); i++) {
		os << ch << _v[i];
		ch = ',';
	}
	os << ')' << endl;

	return os;
}

ostream &operator<<(ostream &os, const WrappedVector &u)
{
	return u.show(os);
}

void WrappedVector::fill()
{
	for (size_t i = 0; i < size(); ++i) {
		_v[i] = 0;
	}
	return;
}

const WrappedVector operator*(const double d, const WrappedVector &v)
{
	return v*d;
}

const WrappedVector operator+(const WrappedVector &v1, const WrappedVector &v2)
{
	WrappedVector res;
	for (size_t i = 0; i < v1.size(); i++) {
		res.coord(i) = v1.coord(i)+v2.coord(i);
	}
	return res;
}

