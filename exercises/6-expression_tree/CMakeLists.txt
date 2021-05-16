cmake_minimum_required(VERSION 3.0.0)
project(a05 VERSION 0.0.0)

add_executable(a05 exptree.cpp main.cpp)

target_compile_options(a05 PRIVATE -Wall -Wextra -pedantic)