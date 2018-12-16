//
// Created by Nick Marhal on 4/17/18.
//

#pragma once

#include "Pair.h"
#include "Sequence.h"

//
template<class T, class P>
class PriorityStack
{
public:
	class BadStack;

	explicit PriorityStack(size_t size) : _stack(new Sequence<Pair<T, P>>(size))
	{
	}

	virtual ~PriorityStack()
	{
		delete _stack;
	}

	void push(const Pair<T, P> & pair)
	{
		__push(pair);
	}

	void pop()
	{
		if (isEmpty())
			throw BadStack("Stack is empty");
		__pop();
	}

	Pair<T, P> const & peek() const
	{
		if (isEmpty())
			throw BadStack("Stack is empty");
		return __peek();
	}

	bool isFull() const
	{
		return _stack->full();
	}

	bool isEmpty() const
	{
		return _stack->empty();
	}

	size_t getSize() const
	{
		return _stack->size();
	}

	size_t getCapacity() const
	{
		return _stack->capacity();
	}

	ostream & print(ostream & os) const
	{
		os << (*_stack);
		return os;
	}

protected:
	Sequence<Pair<T, P>> * _stack;

private:
	virtual void __push(const Pair<T, P> & pair) = 0;

	virtual void __pop() = 0;

	virtual Pair<T, P> const & __peek() const = 0;
};

template<class Key, class Priority>
ostream & operator<<(ostream & os, const PriorityStack<Key, Priority> & stack)
{
	stack.print(os);
	return os;
}

template<class K, class P>
class PriorityStack<K, P>::BadStack
{
private:
	char * _message;
public:
	BadStack(char * message) : _message(message)
	{
	}

	~BadStack()
	{
	}

	const char * getMessage() const
	{
		return _message;
	}

	void trace() const
	{
		cerr << _message << endl;
	}
};