cmake_minimum_required(VERSION 3.10)
project(OOP_FINALS_Marhal)

set(CMAKE_CXX_STANDARD 11)

add_executable(
        OOP_FINALS_Marhal
        main.cpp
        Triangle/Point.cpp Triangle/Point.h
        Triangle/Segment.cpp Triangle/Segment.h
        Triangle/Triangle.cpp Triangle/Triangle.h
        Calendar_Alarm/Calendar.cpp Calendar_Alarm/Calendar.h
        Calendar_Alarm/Date.cpp Calendar_Alarm/Date.h
        Calendar_Alarm/Time.cpp Calendar_Alarm/Time.h
        Calendar_Alarm/Alarm.cpp Calendar_Alarm/Alarm.h
        Stacks/Sequence.h
        Stacks/Array.h
        Stacks/Pair.h Stacks/PriorityStack.h
        Stacks/QuickPeekPriorityStack.h Stacks/QuickPushPriorityStack.h)