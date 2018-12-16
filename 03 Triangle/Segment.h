#ifndef _SEGMENT_H_
#define _SEGMENT_H_

#include "Point.h"
#include <fstream>

#undef NDEBUG
class Segment
{
private:
	static int _call;
	static ofstream out;
	static int freeID;
	int myId;
	Point _a, _b;
public:
	Segment(const double x1=0, const double y1=0,
		const double x2=1, const double y2=0);
	Segment(const Point &start, const Point &end);
	Segment(const Segment&);
	~Segment();
	Segment& operator=(const Segment&);
	const Point& start() const;
	const Point& end() const;
	double length () const;
	double distance (const Point&) const;
	const int getID() const { return myId;}
	static int epilog();
};

ostream& operator<<(ostream &, const Segment &);

#endif