#include <iostream>
#include "String.h"

using namespace std;

int main()
{
	String s1("foo ");
	String s2('A');
	String s3(string("bar"));
	int mul = 3;
	String s4(s1, mul);
	String s5(s3);
	cout << "CONSTRUCTORS" << endl;
	cout << "from char[]: " << s1 << endl
	     << "from char: " << s2 << endl
	     << "from string: " << s3 << endl
	     << "from String (multiplied by " << mul << "): " << s4 << endl
	     << "from String: " << s5 << endl;

	cout << endl << "DESTRUCTOR" << endl;
	String * s = new String("allocated");
	cout << *s << endl;
	delete s;
	cout << *s << endl;

	cout << endl << "ASSIGNMENTS" << endl;
	s1 = String("String");
	s2 = string("std::string");
	s3 = "C-string";
	s4 = 'C';
	cout << "from String: " << s1 << endl
	     << "from std::string: " << s2 << endl
	     << "from C-string: " << s3 << endl
	     << "from char: " << s4 << endl;

	cout << endl << "TYPE GETTERS" << endl;
	cout << "std::string: " << s1.STL_string() << endl;
	cout << "C-string: " << s1.c_str() << endl;
	cout << "length: " << s1.length() << endl;
	cout << endl << "empty() and clear()" << endl;
	cout << "empty?: " << (s1.empty() ? "yes" : "no") << endl;
	cout << "calling clear()" << endl;
	s1.clear();
	cout << "empty?: " << (s1.empty() ? "yes" : "no") << endl;

	cout << endl << "SUBSCRIPTS" << endl;
	try {
		cout << "s2: " << s2 << endl;
		cout << "s2[0]: " << s2[0] << endl;
		cout << "s2[s2.length()-1]: " << s2[s2.length()-1] << endl;
		cout << "s2[s2.length()]: " << s2[s2.length()] << endl;
	} catch (String::BadIndex & e) {
		e.message();
	}
	s2[3] = '(';
	cout << endl << "s2[3] = '(': " << s2 << endl;

	cout << endl << "COMPARISON OPERATORS" << endl;
	cout << "String('a') >= String('b'): " << (String('a') >= String('b')) << endl;
	cout << "(String(\"aa\") < String(\"b\"): )" << (String("aa") < String("b")) << endl;
	cout << "(String(\"string\") <= String(\"string\"): )" << (String("string") <= String("string")) << endl;
	cout << "(String(\"string\") == String(\"string\"): )" << (String("string") == String("string")) << endl;
	cout << "(String(\"string\") != String(\"string\"): )" << (String("string") != String("string")) << endl;

	cout << endl << "+ AND += OPERATORS" << endl;
	s1 = String("str1");
	s2 = String("str2");
	s3 = String("str3");
	string str4 = string(" ");
	//every king of += here:
	cout << (((s1 += str4)+s2))+s3 << endl;
	return 0;
}