//
// Created by Nick Marhal on 1/27/18.
//

#include "point.h"
#include <iostream>

using namespace std;

void test()
{
	Point p1(1, 1);
	cout << "Created : " << p1 << endl;
	Point p2(-2, 3);
	cout << "Created : " << p2 << endl;
	p1.x() = 2;
	p1.y() = -4;
	cout << "Changed using selectors-modifiers : " << p1 << endl;
	cout << "New point as p1+p2 (anonymous) : " << p1+p2 << endl;
	p1 = p2;
	cout << "Changed using assignment operator : " << p1 << endl;
	Point p3(7, -1);
	p1 += p3;
	cout << "Changed using += operator : " << p1 << endl;
	cout << "Equal : " << p1 << " and " << p1 << "? " << ((p1 == p1) ? "yes" : "no") << endl;
	cout << "Non-equal : " << p1 << " and " << p3 << "? " << ((p1 != p3) ? "yes" : "no") << endl;
	Point to_compare(5, 2);
	cout << "Equal : " << p1 << " and " << to_compare << "? " << ((p1 == to_compare) ? "yes" : "no") << endl;
	cout << "New point as p1+p3 (anonymous) : " << p1+p3 << endl;
	Point no_use(0, 0);
	Point another(1, 1);
	cout << "Totally there were created " << Point::amount() << " points (including anonymous)" << endl;
}