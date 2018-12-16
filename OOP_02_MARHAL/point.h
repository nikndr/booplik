//
// Created by Nick Marhal on 1/27/18.
//

#ifndef OOP_02_MARHAL_POINT_H
#define OOP_02_MARHAL_POINT_H

#include <iostream>

using namespace std;

//*******************************************

//Every point possesses its unique ID.

//In debug mode both constructor and destructor

//report the ID and the coordinates

//of a point created or resp. deleted

//Developed by NIKANDR MARHAL

//on 01/27/20!8

//Version 1.1

//*******************************************

class Point
{

	private:

		static unsigned int freeID;

		const unsigned int pointID;

		double _x;

		double _y;

	public:

		Point(double x = 0, double y = 0);

		Point(const Point &);

		~Point();

		Point &operator=(const Point &);

		double &x();

		double &y();

		const double &x() const;

		const double &y() const;

		const unsigned int getID() const;

		double dist_to(const Point &) const;

		static unsigned int amount()
		{
			return freeID;
		}

};


ostream &operator<<(ostream &, const Point &);

const Point operator+(const Point &u, const Point &v);

const Point operator-(const Point &u, const Point &v);

Point &operator+=(Point &, const Point &);

Point &operator-=(Point &u, const Point &v);

bool operator==(const Point &u, const Point &v);

bool operator!=(const Point &u, const Point &v);

#endif //OOP_01_MARHAL_POINT_H
