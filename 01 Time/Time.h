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
	operator double() const;

	int hours() const {return _hours;}
	int minutes() const {return _minutes;}
	int seconds() const {return _seconds;}

	int& hours() {return _hours;}
	int& minutes() {return _minutes;}
	int& seconds() {return _seconds;}
};

int main()
{
	Time t1(1,2,3);
	Time t2(4,5,6);
	cout<<t1<<endl;
	cout<<t2<<endl;
	t1+t2;
	t1+10;
	10+t1;
	10*t1;
	cout<<t1+t2<<endl;
	cout<<Time(t1+t2)<<endl;
	return 0;
}
