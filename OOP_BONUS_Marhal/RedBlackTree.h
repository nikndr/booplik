//
// Created by Nick Marhal on 4/21/18.
//

#pragma once

#include <iostream>

using namespace std;
typedef bool Color;
const Color RED = true;
const Color BLACK = false;

template<class K, class V>
class RedBlackTree
{
private:
	template<K, V>
	class Node<K, V>;

	Node * _root;

public:

	void put(const K & k, const V & v);

	const bool contains(const K & k) const;

	void remove(const K & k);

	const V & get(const K & k) const;

	const bool isEmpty() const;

	const size_t size() const;
};

template<class K, class V>
class RedBlackTree<K, V>::Node<K, V>
{

public:
	K _key;
	V _value;
	Color _color;
	Node <K, V> * _left, * _right, * _parent;
	size_t _size;

	Node(const K & k, const V & v, Color color, size_t size);

	~Node();
};

template<class K, class V>
RedBlackTree<K, V>::Node<K, V> put(Node <K, V> *& x, K & k, V & v)
{
	if (x == nullptr) {
		return new Node(k, v, RED, 1);
	}
};

template<class K, class V>
void RedBlackTree<K, V>::put(const K & k, const V & v)
{
	_root = put(_root, k, v);
	_root->_color = BLACK;
}

template<class K, class V>
const bool RedBlackTree<K, V>::contains(const K & k) const
{
	return 0;
}

template<class K, class V>
void RedBlackTree<K, V>::remove(const K & k)
{

}

template<class K, class V>
const V & RedBlackTree<K, V>::get(const K & k) const
{
	return <#initializer#>;
}

template<class K, class V>
const bool RedBlackTree<K, V>::isEmpty() const
{
	return 0;
}

template<class K, class V>
const size_t RedBlackTree<K, V>::size() const
{
	return 0;
}

template<class K, class V>
RedBlackTree<K, V>::Node<K, V>::Node(const K & k, const V & v, Color color, size_t size) :
		_key(k), _value(v), _size(size), _color(color),
		_left(nullptr), _right(nullptr), _parent(nullptr)
{

}

template<class K, class V>
RedBlackTree<K, V>::Node<K, V>::~Node()
{
	delete _left;
	delete _right;
}



