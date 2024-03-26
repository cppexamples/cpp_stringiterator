cmake_minimum_required(VERSION 3.20)
project(si)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(si stringiterator.cpp)
target_compile_options(si PRIVATE -Ofast) #tail recursion
