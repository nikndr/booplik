//
// Created by Nick Marhal on 4/17/18.
//
#pragma once

#include "ostream"

using namespace std;

template<class Key, class Value>
class Pair
{
public:

	Pair(const Key & key, const Value & value);

	Pair(const Pair<Key, Value> & p);

	Pair()
	{};

	Pair & operator=(const Pair & pair);

	~Pair();

	const Key & key() const;

	const Value & value() const;

private:
	Key _key;
	Value _value;
};

template<class Key, class Value>
ostream & operator<<(ostream & os, const Pair<Key, Value> & p)
{
	os << "{" << (p.key()) << ", " << (p.value()) << "}";
	return os;
}

template<class Key, class Value>
Pair<Key, Value>::Pair(const Key & key, const Value & value): _key(key), _value(value)
{
}

template<class Key, class Value>
Pair<Key, Value>::Pair(const Pair<Key, Value> & p): _key(p._key), _value(p._value)
{
}

template<class Key, class Value>
Pair<Key, Value> & Pair<Key, Value>::operator=(const Pair & pair)
{
	_key = pair.key();
	_value = pair.value();
	return *this;
}

template<class Key, class Value>
Pair<Key, Value>::~Pair()
{
}

template<class Key, class Value>
const Key & Pair<Key, Value>::key() const
{
	return _key;
}

template<class Key, class Value>
const Value & Pair<Key, Value>::value() const
{
	return _value;
}