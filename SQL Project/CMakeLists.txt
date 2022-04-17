cmake_minimum_required(VERSION 3.22)
project(SQL_Project)

set(CMAKE_CXX_STANDARD 11)

add_executable(SQL_Project main.cpp Page.h Index.h Query.h)
