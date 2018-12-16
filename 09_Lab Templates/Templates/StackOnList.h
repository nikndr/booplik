#ifndef _StackOnList_h
#define _StackOnList_h

template <class ListItem>
class SingleList;

template <class Elem>
class StackOnList
{
private:
	int _size;
	
//	Where is located the fist element
	SingleList<Elem> * _top;

public:
	class BadStack{};
	explicit StackOnList();
	virtual ~StackOnList();
	bool empty() const;
	const Elem& top() const;
	void pop();
	void push(Elem value);
	int size() const;
};

#endif
