#ifndef _StackAgregatingArray_h
#define _StackAgregatingArray_h

template <class Elem>
class Array;

template <class Elem>
class StackAgregatingArray
{
private:
	static const int bos; //bottom of stack

protected:
		int _top;
		Array<Elem> * _stackArray;

public:
	class BadStack{};
	explicit StackAgregatingArray(int size);
	virtual ~StackAgregatingArray();
	bool empty() const;
	bool full() const;
	const Elem& top() const;
	void pop();
	void push(Elem value);
	int size() const;
//delegating:
	int volume() const;
};


#endif