#include <iostream>
using namespace std;
//---------------------------------------
// Час
// проаналізувати виконання арифметичних операцій
//---------------------------------------
class Time
{
private:
	int _hours;
	int _minutes;
	int _seconds;
//	Функція службова, а тому закрита
	void normalizeTime();
	
public:
	static const double hourToDec;
	Time (int s=0, int m=0, int h=0);
	Time (const Time&);
	~Time(){};

	Time& operator=(const Time&);
	operator int() const;
	//operator double() const;

	int hours() const {return _hours;}
	int minutes() const {return _minutes;}
	int seconds() const {return _seconds;}

	//int& hours() {return _hours;}
	//int& minutes() {return _minutes;}
	//int& seconds() {return _seconds;}

	int setSeconds(const int s) { 
		_seconds=s;
		normalizeTime();
		return _seconds;
	}
};

ostream & operator<<(ostream & os, const Time & t);
const Time operator+(const Time & t1, const Time & t2);
