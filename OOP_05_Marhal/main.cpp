#include <iostream>
#include "Date.h"

int main()
{
	try {
		Date d1(31, 12, 2000);
		cout << d1 << endl;
		cout << "INCREMENT: " << endl;
		d1++;
		cout << d1 << endl;
		cout << "DECREMENT: " << endl;
		d1--;
		cout << d1 << endl << endl;
		d1.setDay(29);//LEAP YEAR
		d1.setMonth(2);
		cout << d1 << endl;
		cout << "INCREMENT: " << endl;
		++d1;
		cout << d1 << endl;
		cout << "DECREMENT: " << endl;
		--d1;
		cout << d1 << endl;
		d1.setDay(28);//NOT LEAP YEAR. WILL GENERATE ERROR ON OLD DAY VALUE (29)
		d1.setYear(1999);
		cout << "INCREMENT: " << endl;
		++d1;
		cout << d1 << endl;
		cout << "DECREMENT: " << endl;
		--d1;
		cout << d1 << endl << endl;
		Date d2(d1);
		cout << d2 << endl;
		cout << "DEFAULT: " << endl;
		d2.showDefault();
		d2.setDefault(2, 2, 2);
		cout << "DEFAULT AFTER SET: " << endl;
		d2.showDefault();
		d2.setDefault();
		cout << "DEFAULT (CURRENT DATE): " << endl;
		d2.showDefault();
//		d2.setDay(-2); //Generates error
		cout << "SETTING: " << endl;
		d2.setDay(12);
		d2.setMonth(3);
		d2.setYear(1000);
		cout << d2 << endl;
		cout << "MONTH: " << d2.getMonthName() << endl;
	} catch (Date::BadDate &err) {
		cout << err << endl;
	}
	return 0;
}

