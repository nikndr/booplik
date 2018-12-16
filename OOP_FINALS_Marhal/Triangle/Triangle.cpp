//
// Created by Nick Marhal on 2/14/18.
//

#include "Triangle.h"
#include <cmath>

Triangle::Triangle(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3)
		:
		_a(x1, y1), _b(x2, y2), _c(x3, y3), _baseA(0, 0), _baseB(0, 0), _baseC(0, 0), _ab(nullptr), _bc(nullptr),
		_ca(nullptr), _medianA(nullptr), _medianB(nullptr), _medianC(nullptr), _heightA(_a, _baseA),
		_heightB(_b, _baseB), _heightC(_c, _baseC), _medA(nullptr), _medB(nullptr), _medC(nullptr)
{
}

Triangle::Triangle(const Point & a, const Point & b, const Point & c) :
		_a(a), _b(b), _c(c), _baseA(0, 0), _baseB(0, 0), _baseC(0, 0), _ab(nullptr), _bc(nullptr), _ca(nullptr),
		_heightA(_a, _baseA), _heightB(_b, _baseB), _heightC(_c, _baseC), _medianA(nullptr), _medianB(nullptr),
		_medianC(nullptr), _medA(nullptr), _medB(nullptr), _medC(nullptr)
{
}

Triangle::Triangle(const Point & a, const Segment & bc) :
		_a(a), _b(bc.start()), _c(bc.end()), _baseA(0, 0), _baseB(0, 0), _baseC(0, 0), _ab(nullptr), _bc(nullptr),
		_ca(nullptr), _heightA(_a, _baseA), _heightB(_b, _baseB), _heightC(_c, _baseC), _medianA(nullptr),
		_medianB(nullptr), _medianC(nullptr), _medA(nullptr), _medB(nullptr), _medC(nullptr)
{
}

Triangle::Triangle(const Triangle & t) :
		_a(t.apexA()), _b(t.apexB()), _c(t.apexC()), _baseA(t.baseA()), _baseB(t.baseB()), _baseC(t.baseC()),
		_ab(nullptr),
		_bc(nullptr), _ca(nullptr), _heightA(_a, _baseA), _heightB(_b, _baseB), _heightC(_c, _baseC), _medianA(nullptr),
		_medianB(nullptr), _medianC(nullptr), _medA(nullptr), _medB(nullptr), _medC(nullptr)
{
}

Triangle::~Triangle()
{
	delete _ab;
	delete _bc;
	delete _ca;
}

Triangle & Triangle::operator=(const Triangle & t)
{
	delete this;
	_a = t.apexA();
	_b = t.apexB();
	_c = t.apexC();
	return *this;
}

double Triangle::perimeter() const
{
	return side_a().length()+side_b().length()+side_c().length();
}

//This formula was chosen because the implementation uses all three sides instead of one
//Which may cause 3x more errors and therefore is more useful for debugging
double Triangle::area() const
{
	double p = perimeter()/2;
	return sqrt(p*(p-side_a().length())*(p-side_b().length())*(p-side_c().length()));
}

Point & Triangle::apexA() const
{
	return _a;
}

Point & Triangle::apexB() const
{
	return _b;
}

Point & Triangle::apexC() const
{
	return _c;
}

const Segment & Triangle::side_a() const
{
	if (!_bc) {
		_bc = new Segment(_b, _c);
	}
	return *_bc;
}

const Segment & Triangle::side_b() const
{
	if (!_ca) {
		_ca = new Segment(_c, _a);
	}
	return *_ca;
}

const Segment & Triangle::side_c() const
{
	if (!_ab) {
		_ab = new Segment(_a, _b);
	}
	return *_ab;
}

double Triangle::length_a() const
{
	return side_a().length();
}

double Triangle::length_b() const
{
	return side_b().length();
}

double Triangle::length_c() const
{
	return side_c().length();
}

const Point & Triangle::baseA() const
{
	proj(_a, &side_a(), _baseA);
	return _baseA;
}

const Point & Triangle::baseB() const
{
	proj(_a, &side_a(), _baseB);
	return _baseB;
}

const Point & Triangle::baseC() const
{
	proj(_a, &side_a(), _baseC);
	return _baseC;
}

//recalculate the base of the height.
void Triangle::proj(const Point & from, const Segment * to, Point & base) const
{
	double norm_v_x = to->end().y()-to->start().y();
	double norm_v_y = to->start().x()-to->end().x();
	double mpl =
			(to->start().x()*to->end().y()-to->end().x()*to->start().y()+to->start().y()*from.x()-to->end().y()*from.
					x()+to->end().x()*from.y()-to->start().x()*from.y())
			/(norm_v_x*(to->end().y()-to->start().y())+norm_v_y*(to->start().x()-to->end().x()));
	base.x() = from.x()+norm_v_x*mpl;
	base.y() = from.y()+norm_v_y*mpl;
}

const Segment & Triangle::height_a() const
{
	return _heightA;
}

const Segment & Triangle::height_b() const
{
	return _heightB;
}

const Segment & Triangle::height_c() const
{
	return _heightC;
}
//TODO?????????????????????????????????????????
void Triangle::calculateMedian(Point & apex, Point *& basePoint, Segment & side, Segment *& median)
{
	basePoint->x() = (side.endX()+side.startX())/2;
	basePoint->y() = (side.endY()+side.startY())/2;
	Point start(apex);
	Point end(*basePoint);
	if (median == nullptr) {
		median = new Segment(start, end);
	} else {
		median->start() = start;
		median->end() = end;
	}
	cout << *median << endl;
}

const Segment & Triangle::median(const Segment & side)
{
	auto * base = new Point();
	if (side == side_c()) {
		calculateMedian(_c, base, *_ab, _medianC);
		cout << *_medianC << endl;
		return (*_medianC);
	} else if (side == side_a()) {
		calculateMedian(_a, base, *_bc, _medianA);
		return *_medianA;
	} else if (side == side_b()) {
		calculateMedian(_b, base, *_ca, _medianB);
		return *_medianB;
	}
}

ostream & operator<<(ostream & out, const Triangle & t)
{
	return out << "Triangle {\n" << "\t" << t.apexA() << "\n" << "\t" << t.apexB() << "\n" << "\t" << t.apexC()
	           << "\n}";
}