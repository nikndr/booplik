//
// Created by Nick Marhal on 2/10/18.
//
#pragma once

#include <iostream>
#include <cmath>

using namespace std;

class TComplex;

class AComplex
{
private:
	double _re, _im;
	static unsigned int _freeId;
	const unsigned int _id;

public:
	AComplex(double re = 0, double im = 0);

	AComplex(const TComplex &);

	AComplex(const AComplex &);

	~AComplex();

	AComplex &operator=(const AComplex &);

	double &re();

	double &im();

	double re() const;

	double im() const;

	double mod() const;

	double arg() const;

	const AComplex conj() const;

};

AComplex &operator+=(AComplex &, const AComplex &);

AComplex &operator-=(AComplex &, const AComplex &);

AComplex &operator*=(AComplex &, const AComplex &);

AComplex &operator/=(AComplex &, const AComplex &);

const AComplex operator+(const AComplex &, const AComplex &);

const AComplex operator-(const AComplex &, const AComplex &);

const AComplex operator*(const AComplex &, const AComplex &);

const AComplex operator/(const AComplex &, const AComplex &);

const AComplex power(const AComplex &, unsigned int);

bool operator==(const AComplex &, const AComplex &);

bool operator!=(const AComplex &, const AComplex &);

ostream &operator<<(ostream &, const AComplex &);

istream &operator>>(istream &, AComplex &);
