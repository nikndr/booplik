#include <string>
#include <iostream>
using namespace std;

void h();
void hh();

class PublicImplicit
{
private:
	string label;
public:
	PublicImplicit():label("PublicImplicit")
	{
	cout<<"created "<<label<<endl;
	}
	PublicImplicit(const PublicImplicit& a):label(a.label)
	{
	cout<<"copied "<<label<<endl;
	}
	static void g(PublicImplicit a)
	{
	cout<<"parameter by value"<<endl;
	}
};

class PublicExplicit
{
private:
	const string label;
public:
	PublicExplicit():label("PublicExplicit")
	{
	cout<<"created "<<label<<endl;
	}
	explicit PublicExplicit(const PublicExplicit& a):label(a.label)
	{
	cout<<"copied "<<label<<endl;
	}
	static void g(PublicExplicit a)
	{
	cout<<"parameter by value"<<endl;
	}
};

class PrivateExplicit
{
	friend void hh();
private:
	const string label;
	explicit PrivateExplicit(const PrivateExplicit& a):label(a.label)
	{
	cout<<"copied "<<label<<endl;
	}
	public:
	PrivateExplicit():label("PrivateExplicit")
	{
	cout<<"created "<<label<<endl;
	}
	static void g(PrivateExplicit a)
	{
	cout<<"parameter by value"<<endl;
	}
	static void f(const PrivateExplicit& a)
	{
		cout<<"parameter by reference "<<endl;
		cout<<"PrivateExplicit b(a);\t";
		PrivateExplicit b(a);
		cout<<"g(b);\t\t\tdoes not work"<<endl;
//		g(b);
	}
};

class PrivateImplicit
{
	friend void h();
private:
	const string label;
	PrivateImplicit(const PrivateImplicit& a):label(a.label)
	{
	cout<<"copied "<<label<<endl;
	}
public:
	PrivateImplicit():label("PrivateImplicit")
	{
	cout<<"created "<<label<<endl;
	}
	static void g(PrivateImplicit a)
	{
	cout<<"parameter by value"<<endl;
	}
	static void f(const PrivateImplicit& a)
	{
		cout<<"parameter by reference "<<endl;
		cout<<"PrivateImplicit b(a);\t";
		PrivateImplicit b(a);
		cout<<"g(b);\t\t\t";
		g(b);
	}
};

void h()
{
	cout<<"PrivateImplicit a; ";
	PrivateImplicit a;
	cout<<"PrivateImplicit y(x)"<<endl;
	PrivateImplicit b(a);
	PrivateImplicit::g(b);
}

void hh()
{
	PrivateExplicit a;
	PrivateExplicit b(a);
//	PrivateExplicit::g(b);
}
