#include "Word.h"
#include "utils.h"

Word::Word(char* s, size_t len): _s(s), _len(len){}
Word::Word(const Word & src): _s(src._s), _len(src._len){}

Word Word::operator=(const Word &src)
{
	_s = src._s;
	_len = src._len;
	
	return *this;
}

const char* Word::s() const
{
	return _s;
}

const size_t Word::len() const
{
	return _len;
}

char* Word::s()
{
	return _s;
}

size_t Word::len()
{
	return _len;
}

bool operator==(const Word& w1, const Word& w2)
{
	if (w1.len()!= w2.len())
		return false;
	for (size_t i = 0; i < w1.len(); ++i)
		if (lowCase(w1.s()[i]) != lowCase(w2.s()[i]))
			return false;
	return true;
}

bool operator<(const Word& w1, const Word& w2)
{
	size_t n = w1.len()<w2.len()?w1.len():w2.len();
	size_t i = 0;
	while (i<n)
	{ 
		if (w1.s()[i] < w2.s()[i])
			return true;
		if (w1.s()[i] == w2.s()[i])
			++i;
		else
			return false;
	}
	return true;
}

Word takeWord(char* text, size_t& from)
{
	size_t start = from;
	while (separator(text[start]))
		++start;
	size_t end = start;
	while (!separator(text[end++]));
	Word res(new char[end - start], end - start-1);
	for (size_t i = start; i < end-1; ++i)
		res.s()[i - start] = lowCase(text[i]);
	res.s()[end - start-1] = 0;
	from = end;
	return res;
}

bool checkWord(const Word& word, Word* dictionary, size_t currentVolume)
{
	for (size_t i = 0; i < currentVolume; ++i)
		if (dictionary[i] == word)
			return false;
	return true;
}