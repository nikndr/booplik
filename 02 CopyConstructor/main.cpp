#include "1.h"

int main()
{
	cout<<"*** PublicImplicit ***"<<endl;
	cout<<"PublicImplicit a;\t";
	PublicImplicit a;
	cout<<"PublicImplicit b(a);\t";
	PublicImplicit b(a);
	cout<<"PublicImplicit::g(b);\t";
	PublicImplicit::g(b);

	cout<<endl<<"*** PublicExplicit ***"<<endl;
	cout<<"PublicExplicit c;\t";
	PublicExplicit c;
	cout<<"PublicExplicit d(c);\t";
	PublicExplicit d(c);
	cout<<"PublicExplicit::g(d);\tdoes not work"<<endl;
//	PublicExplicit::g(d);
	cout<<endl<<"*** PrivateImplicit ***"<<endl;
	cout<<"PrivateImplicit x;\t";
	PrivateImplicit x;
	cout<<"PrivateImplicit y(x);\tdoes not work"<<endl;
//	PrivateImplicit y(x);
	cout<<"PrivateImplicit::f(x);\t";
	PrivateImplicit::f(x);
	cout<<"PrivateImplicit::g(x);\tdoes not work"<<endl;
//	x.g(x);
	cout<<"h();\t\t\t";
	h();
	cout<<endl<<"*** PrivateExplicit ***"<<endl;
	cout<<"PrivateExplicit u;\t";
	PrivateExplicit u;
	cout<<"PrivateExplicit v(u);\tdoes not work"<<endl;
//	PrivateExplicit v(u);
	cout<<"PrivateExplicit::f(u);\t";
	PrivateExplicit::f(u);
	cout<<"PrivateExplicit::g(u);\tdoes not work"<<endl;
//	PrivateExplicit::g(u);
	cout<<"hh();\t\t\t";
	hh();
	return 0;
}