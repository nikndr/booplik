#include <iostream>

class Word
{
private:
	char* _s;
	size_t _len;

public:
	Word(char* s = "", size_t len = 0);
	Word(const Word &);
	Word operator=(const Word&);

	const char* s() const;
	const size_t len() const;
	
	char* s();
	size_t len();
};

bool operator==(const Word&, const Word&);
bool operator<(const Word&, const Word&);
inline bool operator<=(const Word& a, const Word& b)
{
	return a < b || a == b;
}

Word takeWord(char* text, size_t& from);
bool checkWord(const Word& word, Word* dictionary, size_t currentVolume);
