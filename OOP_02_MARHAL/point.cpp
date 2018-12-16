//
// Created by Nick Marhal on 1/27/18.
//

#include <cmath>
#include "point.h"

using namespace std;

unsigned int Point::freeID = 0;

Point::Point(double x, double y) : pointID(++Point::freeID), _x(x), _y(y)
{
#ifdef NDEBUG
	cout<< "created: "<<*this<<endl;
#endif
}

Point::Point(const Point &p) : pointID(++freeID), _x(p._x), _y(p._y)
{
#ifdef NDEBUG
	cout << "copied: " << *this << endl;
#endif
}

Point::~Point()
{
#ifdef NDEBUG
	cout<<"removed: "<<*this<<endl;
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

double Point::dist_to(const Point &p) const
{
	double xd = _x-p.x();
	double xy = _y-p.y();
	return sqrt(xd*xd+xy*xy);
}


bool operator==(const Point &u, const Point &v)
{
	return u.x() == v.x() && u.y() == v.y();
}

bool operator!=(const Point &u, const Point &v)
{
	return !(u == v);
}

ostream &operator<<(ostream &os, const Point &p)
{
	os << "Point #" << p.getID() << " [" << p.x() << "," << p.y() << "]";
	return os;
}

const Point operator+(const Point &u, const Point &v)
{
	Point cpy(u);
	return cpy += u;
}

const Point operator-(const Point &u, const Point &v)
{
	Point cpy(u);
	return cpy -= u;
}

Point &operator-=(Point &u, const Point &v)
{
	u.x() -= v.x();
	u.y() -= v.y();
	return u;
}

Point &operator+=(Point &u, const Point &v)
{
	u.x() += v.x();
	u.y() += v.y();
	return u;
}
