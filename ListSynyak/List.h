//
//  List.h
//  List
//
//  Created by Oleg on 3/21/18.
//  Copyright (c) 2018 OlegSyniakevych. All rights reserved.
//

#ifndef List_List_h
#define List_List_h
#include "OperatorGenerators.h"
#include <cstdlib>
#include <cassert>
#include <stdexcept>
#include <iso646.h>

template <typename T>
class List {
private:
    struct Node;
    class ListIterator
        : private equality_comparable<ListIterator>
        , private incrementable<ListIterator>
        , private decrementable<ListIterator> {
    friend class List;
    public:
        ListIterator();
        T const & operator*() const;
        ListIterator const & operator++() const;
        ListIterator const & operator--() const;
        bool operator==(ListIterator const & other) const;
    private:
        ListIterator(Node * _start);
        mutable Node * _curr;
    };
public:
    typedef ListIterator iterator;
    List();
    List(T const & first_elem);
    List & cons(T const & elem);
    T const & head();
    List & tail();
    ~List();
    
    size_t size() { return _size; }
    
    iterator begin() const;
    iterator end() const;
private:
    List(List const &);
    List & operator=(List const &);
    
    Node * _first;
    Node * _last;
    size_t _size;
};

// ListNode
template <typename T>
struct List<T>::Node {
    Node (T const & elem, Node * prev, Node * next)
        : _elem(elem) , _prev(prev) , _next(next) {}
    Node (T const & elem): Node(elem, nullptr, nullptr) {}
    
    T _elem;
    Node * _prev;
    Node * _next;
private:
    Node();
};

// ListConstructors
template <typename T>
List<T>::List(T const & first_elem)
: _first(new Node(first_elem))
, _last(_first)
, _size(1)
{}

template <typename T>
List<T>::List()
: _first(nullptr)
, _last(nullptr)
, _size(0)
{}

template <typename T>
List<T>::~List() {
    while (_size) tail();
}
// ListIterator
template <typename T>
T const &
List<T>::ListIterator::operator*() const {
    return _curr->_elem;
}

template <typename T>
typename List<T>::iterator const &
List<T>::ListIterator::operator++() const {
    _curr = _curr->_next;
    return *this;
}

template <typename T>
typename List<T>::iterator const &
List<T>::ListIterator::operator--() const {
    _curr = _curr->_prev;
    return *this;
}

template <typename T>
bool
List<T>::ListIterator::operator==(ListIterator const & other) const {
    return _curr == other._curr;
}

// default gives the end
template <typename T>
List<T>::ListIterator::ListIterator(): _curr(0) {}

template <typename T>
List<T>::ListIterator::ListIterator(Node * start): _curr(start) {}

// list methods
template <typename T>
List<T> & List<T>::cons(T const & elem) {
    if (_first == nullptr) {
        assert(_last == nullptr);
        _first = _last = new Node(elem);
    } else {
        assert(_last != nullptr);
        _last->_next = new Node(elem);
        _last->_next->_prev = _last;
        _last = _last->_next;
    }
 
    ++_size;
    
    return *this;
}

template <typename T>
typename List<T>::iterator List<T>::begin() const {
    return List::iterator(_first);
}

template <typename T>
typename List<T>::iterator List<T>::end() const {
    return List::iterator();
}

template <typename T>
T const & List<T>::head() {
    if (_size == 0) {
        assert(not (_first or _last));
        throw std::runtime_error("trying to get head of empty list");
    }
    return _first->_elem;
}

template <typename T>
List<T> & List<T>::tail() {
    if (_size > 1) {
        assert(_first->_next->_prev == _first);
        _first = _first->_next;
        delete _first->_prev;
        _first->_prev = nullptr;
    } else {
        assert(_first == _last);
        delete _first;
        _first = _last = nullptr;
    }
    
    --_size;
    
    return *this;
}

#endif
