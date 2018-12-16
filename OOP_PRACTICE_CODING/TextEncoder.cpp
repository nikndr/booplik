#include "TextEncoder.h"
#include "utils.h"
TextEncoder::TextEncoder(char * text): _text(text), _table(), _num_letters(0)
{
	char* itor = text;
	while (*itor)
	{
		if('a'<=*itor&&*itor<='z')
		{
			_table.count_ch(lowCase(*itor));
		}
		++itor;
	}

	for (size_t i = 0; i < 26; ++i)
		if (_table.chf()[i].freq() != 0)
			++_num_letters;
		
	

	sortDesc(_table.chf(), 26);	
	encode();
}

unsigned int TextEncoder::char_index(char c)
{
	for (size_t i = 0; i < _num_letters; ++i)
		if (_table.chf()[i].c() == c)
			return i;
	return 0;
}

void TextEncoder::encode()
{
	char * codedText = new char[strlen(_text) + 1];
	for (size_t i = 0; i < strlen(_text); ++i)
	{
		if (separator(_text[i]))
			codedText[i] = _text[i];
		else
		{
			size_t k = char_index(lowCase(_text[i]));
			codedText[i] = _table.chf()[_num_letters - k].c();
		}
	}
	codedText[strlen(_text)] = 0;
	_text = codedText;
}

char* TextEncoder::text()
{
	return _text;
}