//
// Created by Nick Marhal on 4/17/18.
//

#pragma once

#include "PriorityStack.h"

template<class T, class P>
class QuickPeekPriorityStack : public PriorityStack<T, P>
{
private:
	void __push(const Pair<T, P> & t);

	void __pop();

	const Pair<T, P> & __peek() const;

public:
	explicit QuickPeekPriorityStack(size_t size);

};

template<class T, class P>

void QuickPeekPriorityStack<T, P>::__push(const Pair<T, P> & t)
{
#define stack PriorityStack<T,P>::_stack
	size_t i = 0;
	for (; i < stack->size() && (t.value()) < (((*stack)[i]).value()); i++) {

	}
	stack->insert(t, i);
#undef stack
}

template<class T, class P>
void QuickPeekPriorityStack<T, P>::__pop()
{
#define stack PriorityStack<T,P>::_stack
	stack->remove(stack->size()-1);
#undef stack
}

template<class T, class P>
const Pair<T, P> & QuickPeekPriorityStack<T, P>::__peek() const
{
#define stack PriorityStack<T,P>::_stack
	return (*stack)[stack->size()-1];
#undef stack
}

template<class T, class P>
QuickPeekPriorityStack<T, P>::QuickPeekPriorityStack(size_t size):PriorityStack<T, P>(size)
{

}
