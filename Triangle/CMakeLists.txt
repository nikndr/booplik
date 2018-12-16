cmake_minimum_required(VERSION 3.9)
project(Triangle)

set(CMAKE_CXX_STANDARD 11)

add_executable(Triangle main.cpp Point.cpp Point.h Point.txt Segment.cpp Segment.h Segment.txt Triangle.cpp Triangle.h Triangle.txt)