cmake_minimum_required(VERSION 3.9)
project(COmplexCalc)

set(CMAKE_CXX_STANDARD 11)

add_executable(COmplexCalc main.cpp CC.H Complex.cpp Complex.h Wrapper.h)