#pragma once
class CharFreq
{
private:
	char _c;
	int _freq;
public:
	CharFreq(char c='a', int freq = 0);
	char &c();
	int &freq();
	const char c() const;
	const int freq() const;
	void incFreq();
};

inline bool operator>(const CharFreq& a, const CharFreq& b)
{
	return a.freq() > b.freq();
}