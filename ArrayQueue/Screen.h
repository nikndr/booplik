//
// Created by Nick Marhal on 3/22/18.
//

#pragma once

#include <iostream>

using namespace std;

//Запрограмувати меню для роботи з текстовим екраном.

//

//Текстовий екран максимальним розміром

//maxHeigh х maxWidth

//

class Screen
{

private:

	static const int maxHeight;

	static const int maxWidth;

	static const char _filler;

	const unsigned int _height;

	const unsigned int _width;

	const unsigned int _volume;

//Наповнення екрану

	char * _wContent;

	mutable unsigned int _cursor;

	Screen(const Screen &);

	Screen & operator=(const Screen &);

	void fill();

public:

//Екран заповнюється рядком pc,

//якщо він заданий, інакше він наповнюється

//наповнювачем _filler

	Screen(unsigned int, unsigned int, char * pc = 0);

	~Screen();


//Сталітаїмоднойменніметоди

//Перевести курсор на початок екрану

	const Screen & home() const;

	Screen & home();

	void write(const char *);


//Посунути курсор на один символ вправо

	const Screen & move() const;

	Screen & move();


//Посунути курсор на один символ вліво

	const Screen & back() const;

	Screen & back();


//Показативмістекрану

	const Screen & show() const;

	Screen & show();


//Перенести курсор на задану позицію

	const Screen & move(int, int) const;

	Screen & move(int, int);


//Очиститиекран

	Screen & clear();


//Показати символ, на якому знаходиться курсор

	const Screen & showCurrent() const;


//Селектор

	char get() const;

//Модифікатор

	Screen & set(char);

	unsigned int height() const;

	unsigned int width() const;

	const char * content() const;

};


friend ostream & operator<<(ostream &, const Screen &);


typedef const Screen
		& (Screen::* const ConstAction)(void) const;

typedef Screen & (Screen::* const NonConstAction)(void);


void doActionConst(const Screen & s, ConstAction act, int n);

void doActionNonConst(Screen & s, NonConstAction act, int n);

