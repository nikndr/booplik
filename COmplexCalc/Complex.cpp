#include "Complex.h"

Complex::Complex (double re, double im): _re(re), _im (im)
{
#ifndef NDEBUG
	cout<<"Complex number "<<*this<<" created"<<endl;
#endif
};

ostream& operator<<(ostream &os, const  Complex& a)
{
	os<<"("<<a.re()<<'+'<<a.im()<<"i)";
	return os;
}

Complex& Complex::operator= (const Complex& a)
{
	_re = a._re;
	_im = a._im;
	return *this;
}

Complex& operator+=(Complex& a, const Complex& b)
{
	a.re() += b.re();
	a.im() += b.im();
	return a;
}

const Complex operator+(Complex a, const Complex& b)
{
	return a += b;;
}

Complex& operator*=(Complex& a, const Complex& b)
{
	a.re() = a.re()*b.re()-a.im()*b.im();
	a.im() = a.re()*b.im()+a.im()*b.re();
	return a;
}

const Complex  operator* (Complex a, const Complex& b)
{
	return a*=b;
}

bool operator== (const Complex& a, const Complex& b)
{
	return a.re()==b.re()&& a.im()==b.im();
}

bool operator!= (const Complex& a, const Complex& b)
{ 
	return !(a==b);
}

