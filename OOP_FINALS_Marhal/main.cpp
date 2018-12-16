#include <iostream>
#include "Stacks/Pair.h"
#include "Stacks/QuickPeekPriorityStack.h"
#include "Stacks/QuickPushPriorityStack.h"
#include "Calendar_Alarm/Alarm.h"
#include "Triangle/Triangle.h"

void mstack()
{
	QuickPeekPriorityStack<int, double> peek_stack = QuickPeekPriorityStack<int, double>(10);
	QuickPushPriorityStack<int, double> push_stack = QuickPushPriorityStack<int, double>(10);
	try {
		cout << "*****************************STACK*****************************" << endl;
		for (int i = 0; i < 10; i++) {
			peek_stack.push(Pair<int, double>(i, 1.0/(i+1)));
			push_stack.push(Pair<int, double>(-i%5, -1.0/(i+1)));
		}
		cout << endl << "peek stack: " << endl;
		peek_stack.print(cout);
		cout << endl << "push stack: " << endl;
		push_stack.print(cout);
		cout << endl << endl << "getting from peek stack:" << endl;
		for (int i = 0; i < 10; i++) {
			cout << peek_stack.peek() << endl;
			peek_stack.pop();
		}
		cout << endl << "getting from push stack:" << endl;
		for (int i = 0; i < 9; i++) {
			cout << push_stack.peek() << endl;
			push_stack.pop();
		}
	} catch (PriorityStack<int, double>::BadStack & err) {
		err.trace();
	} catch (Array<Pair<int, double>>::BadArray & err) {
		err.trace();
	}
}

void malarm()
{
	try {
		cout << "*****************************ALARM*****************************" << endl;
		struct tm * td;
		time_t timer;
		time(&timer);
		td = gmtime(&timer);
		Date d = Date(td->tm_mday, td->tm_mon+1, 2018);
		Time t = Time(td->tm_hour+2, td->tm_min, td->tm_sec+10);
		Alarm a(d, t, false);
		a.simulate();
	} catch (const char * err) {
		cerr << err << endl;
	}
}

void mtriangle()
{
	cout << "*****************************MEDIAN*****************************" << endl;
	Point p1 = Point(0, 0);
	Point p2 = Point(1, 0);
	Point p3 = Point(0, 1);
	Triangle t = Triangle(p1, p2, p3);
	Segment s(p1, p2);
	cout << t.median(s) << endl;
}

int main()
{
	mtriangle();
	malarm();
	mstack();
	return 0;
}