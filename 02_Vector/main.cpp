#include <iostream>
using namespace std;
#include "Vector.h"
#include "IndexedVector.h"
#include "IndexedVarVector.h"

int main()
{
{
	WrappedVector a, b;
	cout<<a<<a*10<<endl;
	10*a;
	cout<<a+b<<endl;
	cout<<a*b<<endl;
	WrappedVector c(a);
	cout<<boolalpha<<(a==b)<<endl;
	cout<<(a==c)<<endl;
}
{
	IndexedWrappedVector a, b;
	cout<<a<<a*10<<10*a<<endl;
	cout<<a+b<<endl;
	cout<<a*b<<endl;
	IndexedWrappedVector c(a);
	cout<<boolalpha<<(a==b)<<endl;
	cout<<(a==c)<<endl;
	try 
	{
		a[10000];
	} 
	catch(char * err) 
	{
		//cerr << "Smth bad happened" << endl;
		cerr << err << endl;
	} 
	catch(const IndexedWrappedVector::BadVector& err) 
	{
		cerr << "Bad Vector!!!" << endl;
	}
}
{
	IndexedVarVector a, b;
	cout<<a<<a*10<<10*a<<endl;
	cout<<a+b<<endl;
	cout<<a*b<<endl;
	IndexedVarVector c(a);
	cout<<boolalpha<<(a==b)<<endl;
	cout<<(a==c)<<endl;
}
	return 0;
}
