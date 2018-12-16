#include <iostream>
using namespace std;

class IndexedWrappedVector
{
private:
	static const size_t _n;
	double * _v;
public:
	class BadVector{};
	IndexedWrappedVector();
	IndexedWrappedVector(const IndexedWrappedVector&);
	~IndexedWrappedVector();
	size_t size() const { return _n;}
	IndexedWrappedVector& operator=(const IndexedWrappedVector&);

	double operator[](size_t) const;
	double& operator[](size_t);
};

	ostream& operator<<(ostream&, const IndexedWrappedVector&);
	void fill(IndexedWrappedVector& v);
	bool operator==(const IndexedWrappedVector&, const IndexedWrappedVector&);
	bool operator!=(const IndexedWrappedVector&, const IndexedWrappedVector&);
	double operator*(const IndexedWrappedVector&,const IndexedWrappedVector&);
	const IndexedWrappedVector operator*(double, const IndexedWrappedVector&);
	const IndexedWrappedVector operator*( const IndexedWrappedVector&, double);
	const IndexedWrappedVector operator+(const IndexedWrappedVector&,const IndexedWrappedVector&);
