#include <iostream>
using namespace std;

inline char lowCase(const char c)
{
	if ('A' <= c && c <= 'Z')
		return c - ('A' - 'a');
	return c;
}

inline bool separator(char c)
{
	return c == ' ' || c == ',' || c == '.' || c=='\'';
}

template <typename T>
void sort(T* s, size_t n)
{
	for (size_t i = 0; i < n - 1; ++i)
	{
		size_t j = i;
		for (size_t k = i + 1; k < n; ++k)
			if (s[k] < s[j])
				j = k;
		swap(s[j], s[i]);
	}
}

template <typename T>
void sortDesc(T* s, size_t n)
{
	for (size_t i = 0; i < n - 1; ++i)
	{
		size_t j = i;
		for (size_t k = i + 1; k < n; ++k)
			if (s[k] > s[j])
				j = k;
		swap(s[j], s[i]);
	}
}