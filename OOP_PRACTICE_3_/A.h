#ifndef _A_H
#define _A_H

#include <iostream>

using namespace std;

class A
{
	public:
		A(int a = 0) : _a(a), _selfID(++_freeID)
		{
			cout << "a: " << _a << endl;
		}

		~A()
		{
			cout << "destroyed: " << this << endl;
		}

		A& operator=(const A&);
	private:
		int _a;
		static unsigned int _freeID;
		const unsigned int _selfID; //can't use implicit assignment operator
};

#endif //_A_H

