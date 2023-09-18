cmake_minimum_required(VERSION 3.26)
project(ray)

set(CMAKE_CXX_STANDARD 17)

add_executable(ray main.cpp
        test.cpp)
