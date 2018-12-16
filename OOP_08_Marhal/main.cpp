#include <iostream>
#include "Screen.h"

using namespace std;

int main()
{
	int h = 70, w = 10;
	char * text = "Text text text foo bar baz text tex text";
	Screen sc(h, w, text);
	cout << sc;

	sc.move(2, 2);
	char str[] = "something";
	for (size_t i = 0; i < strlen(str); ++i) {
		sc.set(str[i]).move();
	}
	cout << sc;
	for (size_t i = 0; i < strlen(str); ++i) {
		cout << sc.back().get();
	}
	cout << endl;

	sc.home();
	for (size_t i = 0; i < 11; ++i) {
		sc.showCurrent(cout).move();
	}


	cout << endl;
	sc.clear();
	cout << sc;


	const NonConstAction nonConstMenu[] = {&Screen::home, &Screen::move, &Screen::back, &Screen::show, &Screen::clear};
	const ConstAction constMenu[] = {&Screen::home, &Screen::move, &Screen::back, &Screen::show, &Screen::showCurrent};



	const Screen constActionScr(80, 20, text);
	int action, repeat_times;
	char choice;
	bool repeat = true;
	cout << "CONSTANT SCREEN" << endl;
	while (repeat) {
		cout << "0: home, 1: move, 2: back, 3: show, 4: show current: ";
		cin >> action;
		while (action < 0 || action > 4) {
			cout << "Try again: ";
			cin >> action;
		}
		cout << "Repeat times: ";
		cin >> repeat_times;
		while (repeat_times <= 0) {
			cout << "Try again: ";
			cin >> repeat_times;
		}
		doActionConst(constActionScr, constMenu[action], repeat_times);

		cout << endl << "Continue (y/n)?";
		cin >> choice;
		repeat = choice == 'y';
	}

	Screen nonNonstActionsScr(80, 20, text);
	repeat = true;
	cout << "NOT CONSTANT SCREEN" << endl;
	while (repeat) {
		cout << "0: home, 1: move, 2: back, 3: show\n 4: clear, 5: set, 6: move to some point: ";
		cin >> action;
		while (action < 0 || action > 6) {
			cout << "Try again: ";
			cin >> action;
		}
		if (action < 5) {
			cout << "Enter times to do that action: ";
			cin >> repeat_times;
			while (repeat_times <= 0) {
				cout << "Try again: ";
				cin >> repeat_times;
			}
			doActionNonConst(nonNonstActionsScr, nonConstMenu[action], repeat_times);
		}
		if (action == 5) {
			char toSet;
			cout << "Enter the character: ";
			cin >> toSet;
			nonNonstActionsScr.set(toSet);
		}
		if (action == 6) {
			int x, y;
			cout << "Enter the row: ";
			cin >> y;
			cout << "Column: ";
			cin >> x;
			nonNonstActionsScr.move(y, x);
		}
		cout << endl << "Continue (y/n)?";
		cin >> choice;
		repeat = choice == 'y';
	}
}