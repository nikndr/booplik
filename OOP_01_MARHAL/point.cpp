//
// Created by Nick Marhal on 1/27/18.
//

#include "point.h"

using namespace std;

unsigned int Point::freeID = 0;

Point::Point(double x, double y) : pointID(++freeID), _x(x), _y(y)
{}

Point::Point(const Point &p) : pointID(++freeID), _x(p._x), _y(p._y)
{}

Point::~Point()
{
#ifdef NDEBUG
	cout<<pointID<<": removed "<<*this<<endl;
#endif
};

Point &Point::operator=(const Point &p)
{
	_x = p._x;
	_y = p._y;
	return *this;
}

double &Point::x()
{
	return _x;
}

double &Point::y()
{
	return _y;
}

const double &Point::x() const
{
	return _x;
}

const double &Point::y() const
{
	return _y;
}

const unsigned int Point::getID() const
{
	return pointID;
}

bool operator==(const Point &u, const Point &v)
{
	return u.x() == v.x() and u.y() == v.y();
}

bool operator!=(const Point &u, const Point &v)
{
	return not operator==(u, v);
}

ostream &operator<<(ostream &os, const Point &p)
{
	os << "Point #" << p.getID() << " [" << p.x() << "," << p.y() << "]";
	return os;
}

const Point operator+(const Point &u, const Point &v)
{
	return Point(u.x()+v.x(), u.y()+v.y());
}

Point &operator+=(Point &u, const Point &v)
{
	u.x() += v.x();
	u.y() += v.y();
	return u;
}