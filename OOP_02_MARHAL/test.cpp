//
// Created by Nick Marhal on 1/31/18.
//

#include "segment.h"

void test()
{
	Segment s1 = Segment(1, 1, 1, 1);
	Segment s2 = Segment(1, 1, 1, 1);
	cout << s1 << endl;
	cout << s2 << endl;
	cout << "assign s2 to s1: " << endl;
	s1 = s2;
	cout << s1 << endl;
	Point p1 = Point(0, 2);
	cout << p1 << endl;
	Point p2 = Point(-3, -4);
	cout << p2 << endl;
	cout << "creating segment with 2 points: " << endl;
	Segment s3 = Segment(p1, p2);
	cout << s3 << endl;
	cout << "s3's start:  " << endl << s3.start() << endl << "and end point: " << endl << s3.end() << endl;
	cout << "s3's start's X: " << s3.startX() << endl << "and end's Y: " << s3.endY() << endl;
	cout << "Creating const object: " << endl;
	const Segment seg_const = Segment(1, 2, 3, 4);
	cout << seg_const << endl;
	cout << "distance between " << s1 << " __and__ " << p1 << "\n" << s1.distance(p1) << endl;
	cout << "distance between " << s3 << " __and__ " << p1 << "\n" << s3.distance(p1) << endl;
	Segment s4 = Segment(1, 1, 10, 10);
	Point p4 = Point(3, 4);
	cout << "distance between " << s4 << " __and__ " << p4 << "\n" << s4.distance(p4) << endl;
}