#pragma once
#include "CharFreq.h"
class CharFreqTable
{
private:
	CharFreq * _chf;
public:
	CharFreqTable(): _chf(new CharFreq[26]){
		for (char i = 'a'; i <= 'z'; ++i)
		{
			_chf[i-'a'].c() = i;
			_chf[i-'a'].freq() = 0;
		}
	}

	~CharFreqTable()
	{
		delete[] _chf;
		_chf = 0;
	}

	CharFreq *chf()
	{
		return _chf;
	}

	void count_ch(char c)
	{
		_chf[c - 'a'].incFreq();
	}

};