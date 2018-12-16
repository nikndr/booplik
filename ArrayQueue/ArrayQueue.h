//
// Created by Nick Marhal on 3/20/18.
//

#pragma once

#include <iostream>
#include <vector>

using namespace std;

template<class T>
class ArrayQueue
{
private:

	T * _queue;

	int _cur_el;

	int _capacity;

	void reformat()
	{
		T * temp = new T[_capacity];
		for (size_t i = 1, j = 0; i < _cur_el; i++, j++) {
			temp[j] = _queue[i];
		}
		delete[] _queue;
		_queue = temp;
	}

	void resize(int capacity)
	{
		_capacity = capacity;
		T * copy = new T[_capacity];
		for (size_t i = 0; i < _cur_el; i++) {
			copy[i] = _queue[i];
		}
		delete[] _queue;
		_queue = copy;
	}

public:

	explicit ArrayQueue(int initial_capacity = 10) :
			_cur_el(0), _capacity(initial_capacity)
	{
		_queue = new T[_capacity];
	}

	~ArrayQueue()
	{
		delete[] _queue;
		_queue = nullptr;
	}

	ArrayQueue(const ArrayQueue & src) = delete;

	ArrayQueue & operator=(ArrayQueue & src)= delete;
//return i<capacity()-1?i+1:0
	T & dequeue()
	{
		T t = _queue[0];
		reformat();
		_cur_el--;
		if (_cur_el <= _capacity/4) {
			resize(static_cast<int>(_capacity/4));
		}
		return t;
	}

	ArrayQueue & enqueue(const T & t)
	{
		if (_cur_el == _capacity) {
			resize(static_cast<int>(2*_capacity));
		}
		_queue[_cur_el++] = t;
		return *this;
	}

	bool empty() const
	{
		return _cur_el == 0;
	}

	int size() const
	{
		return _cur_el;
	}

	T peek() const
	{
		return _queue[0];
	}

	const T * array() const
	{
		return _queue;
	}
};

template<class T>
ostream & operator<<(ostream & out, ArrayQueue<T> & q)
{
	out << "Your queue: [";
	for (int i = 0; i < q.size(); ++i) {
		if (i != q.size()-1)
			out << q.array()[i] << ", ";
		else
			out << q.array()[i] << "]" << endl;
	}
	return out;

}

