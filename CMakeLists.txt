cmake_minimum_required(VERSION 3.26)
project(TinyJson)

set(CMAKE_CXX_STANDARD 17)

add_executable(TinyJson main.cpp
        Val.h
        cmake-build-debug/Val.cpp
        Val.cpp)
