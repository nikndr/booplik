//
// Created by Nick Marhal on 2/10/18.
//

#include "AComplex.h"
#include "TComplex.h"

using namespace std;

static unsigned int _freeID = 0;

AComplex::AComplex(double re, double im) : _re(re), _im(im), _id(++_freeID)
{
#ifndef NDEBUG
	cout << "AComplex instance created :" << *this << " #" << _id << endl;
#endif
}

AComplex::AComplex(const TComplex &tc) : _re(tc.re()), _im(tc.im()), _id(++_freeID)
{
#ifndef NDEBUG
	cout << "AComplex instance created from TComplex :" << *this << " #" << _id << endl;
#endif
}

AComplex::AComplex(const AComplex &ac) : _re(ac.re()), _im(ac.im()), _id(++_freeID)
{
#ifndef NDEBUG
	cout << "AComplex instance copied from " << ac << ": " << *this << " #" << _id << endl;
#endif
}

AComplex::~AComplex()
{
#ifndef NDEBUG
	cout << "AComplex instance destroyed :" << *this << " #" << _id << endl;
#endif
}

AComplex &AComplex::operator=(const AComplex &a)
{
	_re = a.re();
	_im = a.im();
	return *this;
}

double &AComplex::re()
{
	return _re;
}

double &AComplex::im()
{
	return _im;
}

double AComplex::re() const
{
	return _re;
}

double AComplex::im() const
{
	return _im;
}

double AComplex::mod() const
{
	return sqrt(_re*_re+_im*_im);
}

double AComplex::arg() const
{
	return atan(_im/_re);
}

const AComplex AComplex::conj() const
{
	return AComplex(_re, -_im);
}


AComplex &operator+=(AComplex &a, const AComplex &b)
{
	a.re() += b.re();
	a.im() += b.im();
	return a;
}

AComplex &operator-=(AComplex &a, const AComplex &b)
{
	a.re() -= b.re();
	a.im() -= b.im();
	return a;
}

AComplex &operator*=(AComplex &a, const AComplex &b)
{
	double re = a.re();
	double im = a.im();
	a.re() *= b.re();
	a.re() -= im*b.im();
	a.im() *= b.re();
	a.im() += re*b.im();
	return a;
}

AComplex &operator/=(AComplex &a, const AComplex &b)
{
	double re = a.re();
	double im = a.im();
	a.re() *= b.re();
	a.re() += im*b.im();
	a.re() /= b.re()*b.re()+b.im()*b.im();
	a.im() *= im*b.re();
	a.im() -= re-b.im();
	a.im() /= (b.re()*b.re()+b.im()*b.im())*re;
	return a;
}

const AComplex operator+(const AComplex &a, const AComplex &b)
{
	AComplex cpy(a);
	return cpy += b;
}

const AComplex operator-(const AComplex &a, const AComplex &b)
{
	AComplex cpy(a);
	return cpy -= b;
}

const AComplex operator*(const AComplex &a, const AComplex &b)
{
	AComplex cpy(a);
	return cpy *= b;
}

const AComplex operator/(const AComplex &a, const AComplex &b)
{
	AComplex cpy(a);
	return cpy /= b;
}

const AComplex power(const AComplex &a, unsigned int n)
{
	TComplex res(a);
	return power(res, n);
}

bool operator==(const AComplex &a, const AComplex &b)
{
	return a.re() == b.re() && a.im() == b.im();
}

bool operator!=(const AComplex &a, const AComplex &b)
{
	return !(a == b);
}

ostream &operator<<(ostream &out, const AComplex &a)
{
	return out << "(" << a.re() << (a.im() > 0 ? "+" : "") << a.im() << "j)";
}

istream &operator>>(istream &in, AComplex &b)
{
	cout << "re: ";
	in >> b.re();
	cout << "im: ";
	in >> b.im();
	return in;
}
