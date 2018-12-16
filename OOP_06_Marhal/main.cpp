#include <iostream>
#include "Timer.h"

using namespace std;

int main()
{
	{//testing Time class
		cout << "TESTING TIME CLASS" << endl;
		Time t1 = Time(00, 59, 55);
		cout << "Creating new time:" << endl << t1 << endl;
		Time t2 = t1;
		cout << "Assignment:" << endl << t2 << endl;
		for (int i = 0; i < 6; i++, ++t2) {
			cout << "prefix increment: " << t2 << endl;
		}
		cout << "suffix increment before: " << t2++ << endl;
		cout << "suffix increment after: " << t2 << endl;

		for (int i = 0; i < 6; i++, --t2) {
			cout << "prefix decrement: " << t2 << endl;
		}
		cout << "suffix decrement before: " << t2-- << endl;
		cout << "suffix decrement after: " << t2 << endl;
		cout << "adding times: " << (t1+t2) << endl;
		cout << "Casting to int: " << static_cast<int>(t1) << endl;
		cout << "Casting to double: " << static_cast<double>(t1) << endl;
		cout << "Casting to double: " << static_cast<double>(Time(100, 0, 0)) << endl << endl << endl;
	}

	cout << "TESTING TIMER CLASS" << endl;
	Time interval = Time(0, 0, 3);
	Timer::alertIn(interval);
	{//you could adjust the date and time to make sure it works
		//as I cannot predict the date and time of revision
		Date d = Date(9, 3, 9999);
		Time t = Time(22, 56, 50);
		try {
			Timer * tr = new Timer(d, t, interval);
			tr->await();
			delete tr;
			tr = nullptr;
		} catch (char const * err) {
			cout << err << endl;
		}
	}

	{//will throw error
//		Date d = Date(9, 3, 2017);
//		Time t = Time(23, 56, 50);
//		Time interval = Time(0, 0, 5);
//		try {
//			Timer * tr = new Timer(d, t, interval);
//			tr->await();
//	    	delete tr;
//  		tr = nullptr;
//		} catch (char const * err) {
//			cout << err << endl;
//		}
	}
	return 0;
}