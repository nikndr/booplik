//
// Created by Nick Marhal on 2/10/18.
//
#include <iostream>
#include "AComplex.h"
#include "TComplex.h"

using namespace std;
const double PI = 3.14159265;

int main()
{
	//constructors
	auto a1 = AComplex(1, 1);
	auto t1 = TComplex(1.414213, PI/4);
	cout << a1 << " <-------------> " << t1 << endl;
	auto t2 = TComplex(a1);
	auto a2 = AComplex(t1);
	cout << t2 << " <-------------> " << a2 << endl;

	//assignment and copying
	auto t3 = t2;
	auto a3 = a2;
	cout << a3 << " <-------------> " << t3 << endl;
	auto t4(t3);
	auto a4(a3);
	cout << a4 << " <-------------> " << t4 << endl;

	//operators * / - +
	cout << "Multiplication:" << endl;
	auto a5 = a1*a2*a3;
	cout << a5 << endl;
	auto t5 = t1*t2;
	cout << t5 << endl;
	auto a6 = AComplex(3, 4);
	auto t6 = TComplex(3, PI/10);
	cout << "Division:" << endl;
	cout << a6/a5 << endl;
	cout << t5/t6 << endl;
	auto a7 = AComplex(2, 0);
	auto t7 = TComplex(1.5, PI/2);
	cout << "Subtraction:" << endl;
	cout << a7-t7 << endl;
	cout << "Addition:" << endl;
	cout << a7+t7 << endl;

	//operators *= /= -= +=
	cout << "Multiplication:" << endl;
	cout << (a7 *= a6) << endl;
	cout << "Division:" << endl;
	cout << (t7 /= a6) << endl;
	cout << "Subtraction:" << endl;
	cout << (a6 -= a7) << endl;
	cout << "Addition:" << endl;
	cout << (t7 += a5) << endl;

	//operators == !=
	cout << "Equality:" << endl;
	cout << a3 << " and " << a2 << ": " << ((a3 == a2) ? "equal" : "not equal") << endl;
	cout << a2 << " and " << t1 << ": " << ((a2 == t1) ? "equal" : "not equal") << endl;
	cout << "Inequality:" << endl;
	cout << a1 << " and " << a6 << ": " << ((a2 != a6) ? "not equal" : "equal") << endl;

	//powers
	auto apow = AComplex(1, 1);
	cout << apow << " to the power 1 is: " << power(apow, 1) << endl;
	cout << apow << " to the power 3 is: " << power(apow, 3) << endl;
	auto tpow = TComplex(3, PI);
	cout << tpow << " to the power 1 is: " << power(tpow, 1) << endl;
	cout << tpow << " to the power 5 is: " << power(tpow, 5) << endl;

	//istream
	AComplex x;
	cin >> x;
	cout << x << endl;
	TComplex z;
	cin >> z;
	cout << z;
	return 0;
}