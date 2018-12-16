#include "Segment.h"
#include <cassert>
#include <cmath>

ofstream Segment::out("Segment.txt");
int Segment::freeID = 0;
int Segment::_call=0;

Segment::Segment(const double x1, const double y1,
				 const double x2, const double y2):
		_a(x1, y1), _b(x2, y2),myId(++freeID)
{
	++_call;
#ifndef NDEBUG
	out<<myId<<": a Segment was created: "<<*this;
#endif
};
		
Segment::Segment(const Point &a, const Point &b):
		_a(a), _b(b), myId(++freeID)
{
	++_call;
#ifndef NDEBUG
	out<<myId<<": a Segment was created: "<<*this;
#endif
};
Segment::Segment(const Segment& s): _a(s._a), _b(s._b),myId(++freeID)
{
	++_call;
#ifndef NDEBUG
	out<<myId<<": a Segment was copied: "<<*this;
#endif
}
Segment::~Segment()
{
	++_call;
#ifndef NDEBUG
	out<<myId<<": a Segment was deleted: "<<*this;
#endif
}
Segment& Segment::operator=(const Segment& s)
{
	++_call;
	_a = s._a;
	_b = s._b;
	return *this;
}
double Segment::length () const
{
	++_call;
	return sqrt((_a.x()-_b.x())*(_a.x()-_b.x()) + (_a.y()-_b.y())*(_a.y()-_b.y()));
}

const Point& Segment::start() const
{
	++_call;
	return _a;
}
const Point& Segment::end() const
{
	++_call;
	return _b;
}

double Segment::distance (const Point& c) const
{
	++_call;
	double A = (_a.x()==_b.x()?0:1/(_b.x()-_a.x()));
	double B = (_b.y()==_a.y()?0:1/(_a.y()-_b.y()));
	double C = -_a.x()*A - _a.y()*B;

	assert((A!=0)||(B!=0));

	if (B==0)
		return fabs(-C/A-c.y());
	if (A==0)
		return fabs(-C/B-c.x());

	return fabs((A*c.x()+B*c.y()+C)/sqrt(A*A+B*B));
}

int Segment::epilog()
{
	out<<"N calls "<<_call<<" Total amount of created Segments "<<freeID<<endl;
	return freeID;
}

ostream& operator<<(ostream &os, const Segment& u)
{
	os<<u.getID()<<'['<<u.start()<<','<<u.end()<<']'<<endl;
	return os;
}
