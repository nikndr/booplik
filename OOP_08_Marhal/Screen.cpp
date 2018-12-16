#include "Screen.h"

using namespace std;

const int Screen::maxHeight = 24;
const int Screen::maxWidth = 80;
const char Screen::_filler = '#';

Screen::Screen(int width, int height, char * s) :
		_width(width < maxWidth ? width : maxWidth),
		_height(height < maxHeight ? height : maxHeight), _cursor(0)
{
	int len;
	if (s == 0) {
		len = 0;
	} else {
		len = strlen(s);
	}

	if (len > _height*_width) {
		len = _height*_width;
	}

	_wContent = new char[_height*_width+1];

	_wContent[_height*_width] = '\0';
	int i = 0;
	while (i < len) {
		_wContent[i++] = *s++;
	}
	while (i < _height*_width) {
		_wContent[i++] = _filler;
	}
}

Screen::~Screen()
{
	delete[] _wContent;
}

const Screen & Screen::home() const
{
	_cursor = 0;
	return *this;
};

Screen & Screen::home()
{
	_cursor = 0;
	return *this;
};

const Screen & Screen::move() const
{
	if (_cursor >= _width*_height-1) {
		_cursor = 0;
	} else {
		_cursor += 1;
	}
	return *this;
};

Screen & Screen::move()
{
	if (_cursor >= _width*_height-1) {
		_cursor = 0;
	} else {
		_cursor += 1;
	}
	return *this;
};

const Screen & Screen::back() const
{
	if (_cursor > 0) {
		--_cursor;
	}
	return *this;
};

Screen & Screen::back()
{
	if (_cursor > 0) {
		--_cursor;
	}
	return *this;
};

const Screen & Screen::show(ostream & out) const
{
	int temp = _cursor;
	out << "Cursor: " << _cursor << endl;
	home();
	for (size_t i = 0; i < _height; i++) {
		for (size_t j = 0; j < _width; j++) {
			showCurrent(out).move();
		}
		out << endl;
	}
	_cursor = temp;
	return *this;
};

const Screen & Screen::showCurrent(ostream & out) const
{
	out << get();
	return *this;
}

const Screen & Screen::showCurrent() const
{
	return showCurrent(cout);
}


Screen & Screen::show(ostream & out)
{
	int temp = _cursor;
	out << "Cursor: " << _cursor << endl;
	home();
	for (int i = 0; i < _height; i++) {
		for (int j = 0; j < _width; j++) {
			showCurrent(out).move();
		}
		out << endl;
	}
	_cursor = temp;
	return *this;
};

Screen & Screen::show()
{
	return show(cout);
};

const Screen & Screen::show() const
{
	return show(cout);
};

const Screen & Screen::move(int i, int j) const
{
	if (i < _height && j < _width && i >= 0 && j >= 0) {
		_cursor = _width*i+j;
	} else {
		_cursor = 0;
	}
	return *this;
};

Screen & Screen::move(int i, int j)
{
	if (i < _height && j < _width && i >= 0 && j >= 0) {
		_cursor = _width*i+j;
	} else {
		_cursor = 0;
	}
	return *this;
};

Screen & Screen::clear()
{
	for (int i = 0; i < _height*_width; i++) {
		_wContent[i] = _filler;
	}
	_cursor = 0;
	return *this;
}

char Screen::get() const
{
	return _wContent[_cursor];
};

Screen & Screen::set(char ch)
{
	_wContent[_cursor] = ch;
	return *this;
}

ostream & operator<<(ostream & out, const Screen & sc)
{
	sc.show(out);
	return out;
}

void doActionConst(const Screen & s, ConstAction act, int n)
{
	for (int i = 0; i < n; i++) {
		(s.*act)();
	}
}

void doActionNonConst(Screen & s, NonConstAction act, int n)
{
	for (int i = 0; i < n; i++) {
		(s.*act)();
	}
}