#include <iostream>
#include "A.h"
#include "D.h"
#include "aggregate.h"
#include "B.h"

int main()
{
	{
		int x = 0, y = 2, z = 3;
		(x = y) = z;
	};
	A a = A(1);
	A a1;
	a = a1;
	A a2(a1);
	a1 = a2 = a;

	D d;
	auto res_a = d.f(a);

	B b;
	B b1;
	B b2;
//	b = b1 = b2; operator= return void

	Aggregee aggregee(10);
	Aggregate aggregate(aggregee);
	return 0;
}
