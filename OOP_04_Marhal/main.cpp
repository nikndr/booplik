#include <iostream>
#include "Triangle.h"

using namespace std;

int main()
{
	Triangle t1(0, 0, 1, 0, 0, 1);
	const Triangle &t2(t1);
	cout << t1 << endl;
	cout << t2 << endl;
	cout << "Apexes: " << endl;
	cout << t1.apexA() << " " << t1.apexB() << " " << t1.apexC() << endl;
	cout << "Bases: " << endl;
	cout << t1.baseA() << " " << t1.baseB() << " " << t1.baseC() << endl;
	cout << "Sides: " << endl;
	cout << t1.side_a() << " " << t1.side_b() << " " << t1.side_c() << endl;
	cout << "Heights: " << endl;
	cout << t1.height_a() << " " << t1.height_b() << " " << t1.height_c() << endl;
	cout << "len(a): " << t1.length_a() << "\nlen(b): " << t1.length_b() << "\nlen(c): " << t1.length_c() << endl;
	cout << "Perimeter: " << t1.perimeter() << endl;
	cout << "Area: " << t1.area() << endl;

	cout << "Changing apexes of t2..." << endl;
	t2.apexA() = Point(2, 2);
	t2.apexB() = Point(1.5, -3);
	t2.apexC() = Point(0, 0);

	cout << t2 << endl;
	cout << "Apexes: " << endl;
	cout << t2.apexA() << " " << t2.apexB() << " " << t2.apexC() << endl;
	cout << "Bases: " << endl;
	cout << t2.baseA() << " " << t2.baseB() << " " << t2.baseC() << endl;
	cout << "Sides: " << endl;
	cout << t2.side_a() << " " << t2.side_b() << " " << t2.side_c() << endl;
	cout << "Heights: " << endl;
	cout << t2.height_a() << " " << t2.height_b() << " " << t2.height_c() << endl;
	cout << "len(a): " << t2.length_a() << "\nlen(b): " << t2.length_b() << "\nlen(c): " << t2.length_c() << endl;
	cout << "Perimeter: " << t2.perimeter() << endl;
	cout << "Area: " << t2.area() << endl;
	return 0;
}