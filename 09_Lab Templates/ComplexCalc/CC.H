#include "Complex.h"
#include "Wrapper.h"

class ComplexCalc 
{
	Complex _a, _x;
public:
	ComplexCalc (const Complex& a =0,
			const Complex& x=0): _a(a),_x(x){};
	const Complex& getA() const {return _a; }
	const Complex& getX() const {return _x; }
	void setA (const Complex& a ) { _a = a; }
	void setX (const Complex& x ) { _x = x; }
//   Інфіксний запис тут не проходить: 
	const Complex doOper(CPFR op) {return _a=op(_a,_x);}
};

template <typename Arithm>
class Calc 
{
	Arithm _a, _x;
public:
	Calc (const Arithm& a =0,
			const Arithm& x=0): _a(a),_x(x){};
	const Arithm& getA() const {return _a; }
	const Arithm& getX() const {return _x; }
	void setA (const Arithm& a ) { _a = a; }
	void setX (const Arithm& x ) { _x = x; }
//   Інфіксний запис тут не проходить:
	typedef const Wrapper<Arithm> (* const ArOpPtr) (Wrapper<Arithm>, const Wrapper<Arithm> &);
	const Arithm doOper(ArOpPtr op)
	{
		return _a=op(_a,_x);
	}
};