#include "CC.h"

#define var auto

int main()
{
	Calc<Complex> cc(1, Complex(0, 1));

	cout << cc.getA() << '+' << cc.getX();
	cout << '=' << cc.doOper(operator+) << endl;
	cout << cc.getA() << endl;

	cc.setX(2);
	cout << cc.getA() << '*' << cc.getX();
	cout << '=' << cc.doOper(operator*) << endl;
	cout << cc.getA() << endl;

	Calc<int> ci(1, 2);
	cout << ci.getA() << '+' << ci.getX();
	cout << '=' << ci.doOper(operator+) << endl;
	cout << ci.getA() << endl;

	ci.setX(2);
	cout << ci.getA() << '*' << ci.getX();
	cout << '=' << ci.doOper(operator*) << endl;
	cout << ci.getA() << endl;

	Calc<double> cr(1.5, 2.2);
	cout << cr.getA() << '+' << cr.getX();
	cout << '=' << cr.doOper(operator+) << endl;
	cout << cr.getA() << endl;

	cr.setX(2.5);
	cout << cr.getA() << '*' << cr.getX();
	cout << '=' << cr.doOper(operator*) << endl;
	cout << cr.getA() << endl;

	var x = 2;

	return 0;
}
