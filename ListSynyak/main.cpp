//
//  main.cpp
//  List
//
//  Created by Oleg on 3/21/18.
//  Copyright (c) 2018 OlegSyniakevych. All rights reserved.
//

//#include <iostream>
#include <iostream>
#include "MaxPQ.h"



int main(int argc, const char * argv[])
{
	auto *q = new MaxPQ<int>(10);
	void *p = new MaxPQ<int>(10);
	cout << typeid(&p).name() << endl;
	/*
	List<int> empty_list;
	List<int> list (1);
	std::deque<int> dec;
	dec.push_back(1);
	empty_list.cons(1);
	#define all_push_back(n) dec.push_back(n); empty_list.cons(n); list.cons(n);
	#define all_pop_front() {dec.pop_front(); empty_list.tail(); list.tail(); }
	all_push_back(4);
	all_push_back(5);
	all_pop_front();
	all_pop_front();
	all_push_back(6);
	all_pop_front();
	all_push_back(7);
	#undef all_push_back
	#undef all_pop_front
	assert(empty_list.size() == dec.size());
	assert(empty_list.size() == list.size());
	std::deque<int> empty_list_dec, list_dec;
	for (auto e : empty_list) empty_list_dec.push_back(e);
	for (auto e : list) list_dec.push_back(e);
	assert(list_dec.size() == empty_list_dec.size());
	assert(list_dec.size() == dec.size());
	for (size_t i = 0; i != dec.size(); ++i) {
		assert(list_dec[i] == empty_list_dec[i]);
		assert(list_dec[i] == dec[i]);
	}
	empty_list.cons(1).tail().cons(1).cons(1).tail().cons(2).cons(3);
	list.cons(2).tail().cons(1).cons(3);
	list.tail().tail().tail();
	for (auto el: list) {
		std::cout << el << '\n';
	}
	for (auto el: empty_list) {
		std::cout << el << '\n';
	}
	*/
//	auto * q = new MaxPQ<int>(100);
//	for (int i = 1; i < 10; i++) {
//		for (int j = 1; j < 10; j++) {
//			q->insert(i/j);
//		}
//	}
//
//	for (int i = 0; i < 50; i++) {
//		cout << q->get() << endl;
//	}
	return 0;
}
