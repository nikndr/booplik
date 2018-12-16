//
// Created by Nick Marhal on 2/14/18.
//

#include <cmath>
//#include "Segment.h"
#include "Triangle.h"


using namespace std;

unsigned int Segment::_freeID = 0;

Segment::Segment(Point & start, Point & end) :
		_selfID(++_freeID), _start(start), _end(end)
{
#ifndef NDEBUG
//	cout << "creating " << *this << endl;
#endif
}

Segment::Segment(Segment & source) :
		_selfID(++_freeID), _start(source.start()), _end(source.end())
{
#ifndef NDEBUG
//	cout << "copying " << *this << endl;
#endif
}

Segment::~Segment()
{
#ifndef NDEBUG
//	cout << "deleting " << *this << endl;
#endif
}

Segment & Segment::operator=(const Segment & source)
{
	_start = source.start();
	_end = source.end();
	return *this;
}

const Point & Segment::start() const
{
	return _start;
}

const Point & Segment::end() const
{
	return _end;
}

Point & Segment::start()
{
	return _start;
}

Point & Segment::end()
{
	return _end;
}

const double & Segment::startX() const
{
	return start().x();
}

const double & Segment::startY() const
{
	return start().y();
}

const double & Segment::endX() const
{
	return end().x();
}

const double & Segment::endY() const
{
	return end().y();
}

double & Segment::startX()
{
	return const_cast<double &>(start().x());
}

double & Segment::startY()
{
	return const_cast<double &>(start().y());
}

double & Segment::endX()
{
	return const_cast<double &>(end().x());
}

double & Segment::endY()
{
	return const_cast<double &>(end().y());
}

double Segment::length() const
{
	return length(end(), start());
}

double Segment::length(const Point & p1, const Point & p2) const
{
	double x = abs(p1.x()-p2.x());
	double y = abs(p1.y()-p2.y());
	return sqrt(x*x+y*y);
}


double Segment::distance(const Point & p) const
{
	double sp = _start.dist_to(p);
	double ep = _end.dist_to(p);
	double se = _start.dist_to(_end);
	if (sp >= sqrt(ep*ep+se*se)) {
		return ep;
	}
	if (ep >= sqrt(sp*sp+se*se)) {
		return sp;
	}
	double hf_prm = (sp+ep+se)/2;
	return 2*sqrt(hf_prm*(hf_prm-sp)*(hf_prm-ep)*(hf_prm-se))/se;
}

const int Segment::getID() const
{
	return _selfID;
}

ostream & operator<<(ostream & os, const Segment & segment)
{
	os << "Segment #" << segment.getID() <<
	   "{ "
	   << segment.start() << " <-> " << segment.end() <<
	   " }";
	return os;
}

bool operator==(const Segment & s1, const Segment & s2)
{
	return (s1.start() == s2.start() && s1.end() == s2.end())
	       || (s1.start() == s2.end() && s1.end() == s2.start());
}
