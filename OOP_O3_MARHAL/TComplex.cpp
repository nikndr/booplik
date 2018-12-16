//
// Created by Nick Marhal on 2/10/18.
//
#include "AComplex.h"
#include "TComplex.h"

using namespace std;

static unsigned int _freeID = 0;

TComplex::TComplex(double ro, double phi) : _mod(ro), _arg(phi), _id(++_freeID)
{
#ifndef NDEBUG
	cout << "TComplex instance created :" << *this << " #" << _id << endl;
#endif
}

TComplex::TComplex(const TComplex &a) : _mod(a.mod()), _arg(a.arg()), _id(++_freeID)
{
#ifndef NDEBUG
	cout << "TComplex instance copied :" << *this << " #" << _id << endl;
#endif
}

TComplex::TComplex(const AComplex &a) : _mod(a.mod()), _arg(a.arg()), _id(++_freeID)
{
#ifndef NDEBUG
	cout << "TComplex instance created from AComplex :" << *this << " #" << _id << endl;
#endif
}

TComplex::~TComplex()
{
#ifndef NDEBUG
	cout << "TComplex instance destroyed :" << *this << " #" << _id << endl;
#endif
}

TComplex &TComplex::operator=(const TComplex &a)
<%
	_mod = a.mod();
	_arg = a.arg();
	return *this;
%>

double &TComplex::mod()
{
	return _mod;
}

double &TComplex::arg()
{
	return _arg;
}

double TComplex::mod() const
{
	return _mod;
}

double TComplex::arg() const
{
	return _arg;
}

double TComplex::re() const
{
	return _mod*cos(_arg);
}

double TComplex::im() const
{
	return _mod*sin(_arg);
}

TComplex &operator+=(TComplex &a, const TComplex &b)
{
	AComplex ac(a);
	AComplex bc(b);
	a = (ac += bc);
	return a;
}

TComplex &operator-=(TComplex &a, const TComplex &b)
{
	AComplex ac(a);
	AComplex bc(b);
	a = (ac -= bc);
	return a;
}

TComplex &operator*=(TComplex &a, const TComplex &b)
{
	a.mod() *= b.mod();
	a.arg() += b.arg();
	return a;

}

TComplex &operator/=(TComplex &a, const TComplex &b)
{
	a.mod() /= b.mod();
	a.arg() -= b.arg();
	return a;
}

const TComplex operator*(const TComplex &a, const TComplex &b)
{
	TComplex cpy(a);
	return cpy *= b;
}

const TComplex operator/(const TComplex &a, const TComplex &b)
{
	TComplex cpy(a);
	return cpy /= b;
}

const TComplex power(const TComplex &a, unsigned int n)
{
	double mod = pow(a.mod(), n);
	double arg = a.arg()*n;
	return TComplex(mod, arg);
}

ostream &operator<<(ostream &out, const TComplex &a)
{
	return out << a.mod() << "(cos(" << a.arg() << ")" << "+isin(" << a.arg() << "))";

}

istream &operator>>(istream &in, TComplex &b)
{
	cout << "mod: ";
	in >> b.mod();
	cout << "arg: ";
	in >> b.arg();
	return in;
}





