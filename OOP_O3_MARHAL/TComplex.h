//
// Created by Nick Marhal on 2/10/18.
//
#pragma once

#include <iostream>
#include <cmath>

using namespace std;

class AComplex;

class TComplex
{
private:
	double _mod, _arg;
	static unsigned int _freeId;
	const unsigned int _id;

public:
	TComplex(double ro = 0, double phi = 0);

	TComplex(const TComplex &);

	TComplex(const AComplex &);

	~TComplex();

	TComplex &operator=(const TComplex &);

	double &mod();

	double &arg();

	double mod() const;

	double arg() const;

	double re() const;

	double im() const;

};

TComplex &operator+=(TComplex &a, const TComplex &b);

TComplex &operator-=(TComplex &a, const TComplex &b);

TComplex &operator*=(TComplex &a, const TComplex &b);

TComplex &operator/=(TComplex &a, const TComplex &b);

const TComplex operator*(const TComplex &, const TComplex &);

const TComplex operator/(const TComplex &, const TComplex &);

const TComplex power(const TComplex &, unsigned int);

ostream &operator<<(ostream &, const TComplex &);

istream &operator>>(istream &, TComplex &);