#ifndef _Array_h
#define _Array_h

#define _DEBUG_

template <class ArrayElem>
class Array
{

public:
	class BadArray{};
	Array (int sz);
	Array (const Array&);
	virtual ~Array();
	virtual bool operator== (const Array& a) const;
	virtual bool operator!= (const Array& a) const;
	Array& operator= (const Array& a);
	ArrayElem& operator[] (int index);
	const ArrayElem& operator[] (int index) const;
	int size() const;	
private:
	int _size;

protected:
	ArrayElem *ia;
};
#endif