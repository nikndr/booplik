class A;

class B
{
	public:
		A &f(A &);
		A *g(A *);
		void operator=(const B&);
};