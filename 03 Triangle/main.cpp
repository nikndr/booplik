#include "Point.h"
#include "Segment.h"
#include "Triangle.h"

#include <iostream>
using namespace std;

int main()
{ 
	Point u, v(0,3), w (4);

	cout<<"Triangle composing apices======"<<endl;
	Triangle ABC(u, v, w);
	cout<<"ABC "<<ABC;

	Triangle a, b(2,0,2,2,0,2), c(b);
	cout<<"a "<<a;

	cout<<"b "<<b;

	cout<<"c "<<c;

	c=ABC;
	cout<<"new value of c "<<c;

	cout<<"Triangles "<<Triangle::epilog()<<endl;
	cout<<"Segments  "<<Segment::epilog()<<endl;
	cout<<"Points    "<<Point::epilog()<<endl;

	//59 of points; 22 of segments

	return 0;
}
