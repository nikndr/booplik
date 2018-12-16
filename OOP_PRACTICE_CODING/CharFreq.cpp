#include "CharFreq.h"

CharFreq::CharFreq(char c, int freq): _c(c), _freq(freq){};

char& CharFreq::c()
{
	return _c;
}

int& CharFreq::freq()
{
	return _freq;
}

const int CharFreq::freq() const
{
	return _freq;
}

const char CharFreq::c() const
{
	return _c;
}


void CharFreq::incFreq() 
{
	++_freq;
}


