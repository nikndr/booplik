cmake_minimum_required(VERSION 3.10)
project(ListSynyak)

set(CMAKE_CXX_STANDARD 11)

add_executable(ListSynyak main.cpp List.h OperatorGenerators.h MaxPQ.h)