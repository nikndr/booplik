//
//  OperatorGenerators.h
//  Time
//
//  Created by User on 3/10/18.
//  Copyright (c) 2018 Oleg. All rights reserved.
//

#ifndef Time_OperatorGenerators_h
#define Time_OperatorGenerators_h

#include <iso646.h>

template <class T>
struct equality_comparable {
    friend bool
    operator!=(T const & lhs, T const & rhs) { return not (lhs == rhs); }
};


template <class T>
struct less_comparable {
    friend bool operator>(T const & lhs, T const & rhs) { return rhs < lhs; }
    friend bool operator<=(T const & lhs, T const & rhs) { return not (lhs > rhs); }
    friend bool operator>=(T const & lhs, T const & rhs) { return rhs <= rhs; }
};

template <class T>
struct incrementable {
    friend T operator++(T & self, int) {
        T old(self);
        ++self;
        return old;
    }
};

template <class T>
struct decrementable {
    friend T operator--(T & self, int) {
        T old(self);
        --self;
        return old;
    }
};

#endif
