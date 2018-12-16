//
// Created by Nick Marhal on 3/22/18.
//

#include "Screen.h"

const size_t Screen::maxHeight = 24;
const size_t Screen::maxWidth = 80;
const char Screen::_filler = '_';

Screen::Screen(const size_t m, const size_t n, char* s):
		_width(m>maxWidth? maxWidth :m), _height(n>maxHeight? maxHeight :n), _wContent(new char[_height*_width+1]), size_t lens = s==0?0:strlen(s);
// Якщо довжина рядка наповнення надто велика, урізаємо його
size_t len=lens>_height*_width? _height*_width :lens;
// Його заповнення починаємо з кінця символом закінчення рядка
_wContent[_height*_width]='\0'; size_t k=0;
if(s!=0)
// Записуємо на початку екрана рядок, переданий як параметр
for(; k<len; k++) *(_wContent+k)=*s++;
// Заповнюємо екран до кінця наповнювачем for(; k<_height*_width; k++)
*(_wContent+k)=_filler; }

Screen::~Screen()
{
	delete[] _wContent;
	_wContent = nullptr;
}

void Screen::fill()
{
	for (size_t i = 0; i < _volume; i++) {
		_wContent[i] = _filler;
	}
}

void Screen::write(const char * text)
{
	size_t len = strlen(text);
	for (size_t i = 0; i < len && i < _volume; i++) {
		_wContent[i] = text[i];
		_cursor = (++_cursor)%_volume;
	}
}

Screen & Screen::clear()
{
	fill();
	return *this;
}

const Screen & Screen::showCurrent() const
{
	cout << _wContent[_cursor];
	return *this;
}

char Screen::get() const
{
	return _wContent[_cursor];
}

Screen & Screen::set(char c)
{
	_wContent[_cursor] = c;
	return *this;
}

Screen & Screen::move(int x, int y)
{
	x %= _width;
	y %= _height;
	_cursor = x+y*_height;
	return *this;
}

const Screen & Screen::move(int x, int y) const
{
	x %= _width;
	y %= _height;
	_cursor = x+y*_height;
	return *this;
}

const Screen & Screen::move() const
{
	_cursor = (++_cursor)%_volume;
	return *this;
}

Screen & Screen::move()
{
	_cursor = (++_cursor)%_volume;
	return *this;
}

const Screen & Screen::back() const
{
	if (_cursor == 0) {
		_cursor = _volume-1;
	} else {
		_cursor = (--_cursor)%_volume;
	}
	return *this;
}

Screen & Screen::back()
{
	if (_cursor == 0) {
		_cursor = _volume-1;
	} else {
		_cursor = (--_cursor)%_volume;
	}
	return *this;
}

//returns cursor to the beginning of the line
const Screen & Screen::home() const
{
	unsigned int x_delta(_cursor%_height);
	_cursor -= x_delta;
	return *this;
}

Screen & Screen::home()
{
	unsigned int x_delta(_cursor%_height);
	_cursor -= x_delta;
	return *this;
}

const Screen & Screen::show() const
{
	for (size_t y = 0; y < _height; y++) {
		for (size_t x = 0; x < _width; x++) {
			cout << _wContent[x+y*_height];
		}
		cout << endl;
	}
	return *this;
}

Screen & Screen::show()
{
	for (size_t y = 0; y < _height; y++) {
		for (size_t x = 0; x < _width; x++) {
			cout << _wContent[x+y*_height];
		}
		cout << endl;
	}
	return *this;
}

unsigned int Screen::height() const
{
	return _height;
}

unsigned int Screen::width() const
{
	return _width;
}

const char * Screen::content() const
{
	return _wContent;
}

void doActionConst(const Screen & s, ConstAction act, int n)
{
	for (int i = 0; i < n; i++) {
		s.*act();
	}
}

void doActionNonConst(Screen & s, NonConstAction act, int n)
{
	for (int i = 0; i < n; i++) {
		s.*act();
	}
}

ostream & operator<<(ostream & out, const Screen & s)
{
	for (size_t y = 0; y < s.height(); y++) {
		for (size_t x = 0; x < s.width(); x++) {
			cout << s.content()[x+y*s.height()];
		}
		cout << endl;
	}
	return out;
}
