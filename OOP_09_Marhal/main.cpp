#include <iostream>
#include "Array.h"

using namespace std;


int main()
{
	//testing size 10 class int
	Array<10, int> arr = Array<10, int>();
	cout << "Array of 10 elements (default):\n" << arr << endl;
	for (size_t i = 0; i < arr.length(); i++) {
		arr[i] = static_cast<int>(i*i);
	}
	cout << "After fill:\n" << arr << endl;
	Array<10, int> new_arr = Array<10, int>();
	for (size_t i = 0; i < arr.length(); i++) {
		new_arr[i] = static_cast<int>(i*i-i*i*i);
	}
	cout << "New array:\n" << new_arr << endl;
	arr = new_arr;
	cout << "Old array after assignment:\n" << arr << endl;
	cout << "Length:\n" << arr.length() << endl;
	try {
		cout << "Getting 100-th element of an array:\n" << endl;
		arr[100] = 0;
	} catch (Array<10, int>::BadArray & err) {
		err.trace();
	}
	arr[0] = 15.2;
	cout << arr << endl;
	//double being casted to int when passing into Array of type double

	Array<15, double> arr_dbl = Array<15, double>();
	//arr = arr_fifteen;//will throw an error because of uncompatible template parameter
	for (size_t j = 0; j < 15; j++) {
		arr_dbl[j] = static_cast<double>(j)/13.5;
	}
	cout << arr_dbl << endl;
	arr_dbl[0] = static_cast<int>(100.0);
	cout << arr_dbl << endl << "type of first element: " << typeid(arr_dbl[0]).name() << endl;
	//int being casted to dobule when passing into Array of type double
	try {
		arr_dbl[15] = 1;
	} catch (Array<15, double>::BadArray & err) {
		err.trace();
	}
	return 0;
}