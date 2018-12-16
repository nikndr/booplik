#include "Array.h"

int main()
{
	Array ar(10);
	for(size_t i=0; i<ar.size(); i++)
		ar[i] = i;
	cout<<ar<<endl;
	return 0;
}