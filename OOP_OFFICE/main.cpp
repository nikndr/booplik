#include <iostream>
using namespace std;
#include "Person.h"
#include "Position.h"
#include "Employer.h"
#include "Employee.h"
#include "Accountant.h"

const int npersonnel = 7;
const int nestablishement = 3;
const int nstaff = 5;

int main()
{
	cout<<"***Start office"<<endl;

	//Data base personnel
	Person personnel[npersonnel]=
	{
		Person("Wano"),
		Person("Dick"),
		Person("Lee"),
		Person("Pete"),
		Person("Bob"),
		Person("Joe"),
		Person("Jane")
	};
	
	Person accountant("Anna");
	Person copy(accountant);
	Person employer("Boss");

	//Data base establishment
	Position establishment[nestablishement]=
	{
		Position("Analyst", 1000),
		Position("Coder", 800),
		Position("Tester", 900)
	};

	for (int i=0; i<npersonnel; i++)
		cout<<personnel[i].getName()<<endl;
	for (int i=0; i<nestablishement; i++)
		cout<<establishment[i].getPositionName()<<endl;

	Employer theSoftPro(employer,nstaff,accountant);
	
	theSoftPro.hire (personnel[0], establishment[0]);
	theSoftPro.hire (personnel[1], establishment[1]);
	theSoftPro.hire (personnel[2], establishment[1]);
	theSoftPro.hire (personnel[3], establishment[2]);
	theSoftPro.hire (personnel[4], establishment[2]);

	theSoftPro.pay();

	cout<<"***Stop office"<<endl;
	return 0;
}