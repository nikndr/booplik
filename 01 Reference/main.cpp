#include "1.h"
#include <iostream>
using namespace std;

int main()
{	
	Component d;
	Composit c;
	c.get()=d;
	cout<< &c.get()<<endl;
	c.getref()=d;
	cout<< &c.getref()<<endl;

	const Composit cc(c);
	cc.get()=d;
	cout<< &cc.get()<<endl;
//	cc.getref()=d;
	cout<< &cc.getref()<<endl;
	return 0;
}