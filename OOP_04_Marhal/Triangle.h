//
// Created by Nick Marhal on 2/14/18.
//

#pragma once

//*******************************************

//    Lab task 4

//    Developed by Nikandr Marhal

//    at 2/14/20!8

//    Version 1.0

//*******************************************

#include "Segment.h"
#include "Point.h"

class Triangle
{

private:

	mutable Point _a, _b, _c;
	mutable Point _baseA, _baseB, _baseC;
	mutable Segment *_ab, *_bc, *_ca;
	mutable Segment _heightA, _heightB, _heightC;

	void proj(const Point &from, const Segment *to, Point &base) const;

public:

	explicit Triangle(const double x1 = 0, const double y1 = 0,

	                  const double x2 = 1, const double y2 = 0,

	                  const double x3 = 0, const double y3 = 1);

	Triangle(const Point &a, const Point &b, const Point &c);

	Triangle(const Point &a, const Segment &_bc);


	Triangle(const Triangle &);

	~Triangle();

	Triangle &operator=(const Triangle &);

	double perimeter() const;

	double area() const;

// Apexes

	Point &apexA() const;

	Point &apexB() const;

	Point &apexC() const;

	const Point &baseA() const;

	const Point &baseB() const;

	const Point &baseC() const;


// Sides

	const Segment &side_a() const;

	const Segment &side_b() const;

	const Segment &side_c() const;


// Sides' lengths

	double length_a() const;

	double length_b() const;

	double length_c() const;


// Heights

	const Segment &height_a() const;

	const Segment &height_b() const;

	const Segment &height_c() const;


};


ostream &operator<<(ostream &, const Triangle &);
