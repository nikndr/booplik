// ���� ���������� �������
class WrappedVector
{
private:
	static const size_t _n;
	double *_v;

	void fill();

public:
// ����������� ���� �������
	WrappedVector();

	WrappedVector(const WrappedVector &);

	WrappedVector &operator=(const WrappedVector &);

	~WrappedVector();

// ��������
	size_t size() const
	{ return _n; }

	const double &coord(size_t i) const
	{ return _v[i]; }

	double &coord(size_t i)
	{ return _v[i]; }

// ���� ������������� ��������
	bool operator==(const WrappedVector &) const;

	bool operator!=(const WrappedVector &) const;

	double operator*(const WrappedVector &) const;

	const WrappedVector operator*(double) const;

	/*const WrappedVector operator+
	   (const WrappedVector&) const;*/
	ostream &show(ostream &os) const;
};

ostream &operator<<(ostream &os, const WrappedVector &u);

const WrappedVector operator*(const double, const WrappedVector &);

const WrappedVector operator+(const WrappedVector &, const WrappedVector &);