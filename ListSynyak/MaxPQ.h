//
// Created by Nick Marhal on 4/10/18.
//

#ifndef _MAXPQ_H
#define _MAXPQ_H

#include <iostream>

using namespace std;

template<class T>
void exch(T * a, T * b)
{
	if (a != b) {
		*a ^= *b;
		*b ^= *a;
		*a ^= *b;
	}
}

template<class T>
class MaxPQ
{
private:
	T * pq;
	size_t els;
public:
	MaxPQ(int maxN)
	{
		pq = new T[maxN]();
		els = 0;
	}

	~MaxPQ()
	{
		delete[] pq;
		pq = nullptr;
	}

	int empty() const
	{
		return els == 0;
	}

	void insert(T item)
	{
		pq[els++] = item;
	}

	T get()
	{
		size_t max = 0;
		for (size_t j = 1; j < els; j++) {
			if (pq[max] < pq[j])
				max = j;
		}
		exch(&pq[max], &pq[els-1]);
		return pq[--els];
	}
};

#endif //_MAXPQ_H