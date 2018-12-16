//
// Created by Nick Marhal on 2/14/18.
//

#ifndef OOP_02_MARHAL_SEGMENT_H
#define OOP_02_MARHAL_SEGMENT_H

#include <iostream>
#include "Point.h"
#include "Triangle.h"

using namespace std;
//*******************************************

//Every segment possesses its unique ID.

//In debug mode both constructor and destructor

//report the ID and the coordinates

//of a segment created or resp. deleted

//Developed by NIKANDR MARHAL

//at 31/01/20!8

//Version 1.2

//*******************************************
class Segment
{

private:

	static unsigned int _freeID;

	const unsigned int _selfID;

	Point &_start;

	Point &_end;

	double length(const Point &, const Point &) const;


public:

	Segment(Point &start, Point &end);

	Segment(Segment &);

	~Segment();

	Segment &operator=(const Segment &);

	const Point &start() const;

	const Point &end() const;

	Point &start();

	Point &end();

	const double &startX() const;

	const double &startY() const;

	const double &endX() const;

	const double &endY() const;

	double &startX();

	double &startY();

	double &endX();

	double &endY();

	double length() const;

	double distance(const Point &) const;

	const int getID() const;

	static const unsigned int amount()
	{
		return _freeID;
	}

};


ostream &operator<<(ostream &, const Segment &);

#endif //OOP_02_MARHAL_SEGMENT_H
