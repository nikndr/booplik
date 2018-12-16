//
// Created by Nick Marhal on 4/17/18.
//

#pragma once

#include "PriorityStack.h"

template<class T, class P>
class QuickPushPriorityStack : public PriorityStack<T, P>
{
private:
	void __push(const Pair<T, P> & t);

	void __pop();

	const Pair<T, P> & __peek() const;

	size_t topPriorityIndex() const;

public:
	explicit QuickPushPriorityStack(size_t size);

};

template<class T, class P>
void QuickPushPriorityStack<T, P>::__push(const Pair<T, P> & t)
{
#define stack PriorityStack<T,P>::_stack
	stack->append(t);
#undef stack
}

template<class T, class P>
void QuickPushPriorityStack<T, P>::__pop()
{
#define stack PriorityStack<T,P>::_stack
	stack->remove(topPriorityIndex());
#undef stack
}

template<class T, class P>
const Pair<T, P> & QuickPushPriorityStack<T, P>::__peek() const
{
#define stack PriorityStack<T,P>::_stack
	return (*stack)[topPriorityIndex()];
#undef stack
}

template<class T, class P>
QuickPushPriorityStack<T, P>::QuickPushPriorityStack(size_t size):PriorityStack<T,P>(size)
{

}

template<class T, class P>
size_t QuickPushPriorityStack<T, P>::topPriorityIndex() const
{
#define stack PriorityStack<T,P>::_stack
	size_t ind = 0;
	for (size_t i = 1; i < PriorityStack<T, P>::getSize(); ++i) {
		if ((*stack)[ind].value() < (*stack)[i].value()) {
			ind = i;
		}
	}
	return ind;
#undef stack
}



