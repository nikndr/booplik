#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include <iostream>
#include <fstream>
using namespace std;

// Версія 1.1 Композиція вершин
class Triangle
{
private:
	static ofstream out;
	static int _call;
	Point _a, _b, _c;

public:
	Triangle(const double x1=0, const double y1=0,
		const double x2=1, const double y2=0,
		const double x3=0, const double y3=1);
	Triangle(const Point &a,
		const Point& b, 
		const Point& c);
	Triangle (const Triangle&);
	~Triangle();
	Triangle& operator= (const Triangle&);
	double perimeter() const;
	double area() const;

	const Point& apexA() const;
	const Point& apexB() const;
	const Point& apexC() const;

	const Segment side_a() const;
	const Segment side_b() const;
	const Segment side_c() const;

	static int epilog();

	ostream& show (ostream & os) const;
};

ostream& operator<<(ostream &, const Triangle &);
#endif
