#pragma once
#include "CharFreqTable.h"
#include "CharFreq.h"
#include <iostream>
class TextEncoder
{
private:
	char * _text;
	CharFreqTable _table;
	size_t _num_letters;
	unsigned int char_index(char c);
public:
	TextEncoder(char * text);
	void encode();
	char * text();
};