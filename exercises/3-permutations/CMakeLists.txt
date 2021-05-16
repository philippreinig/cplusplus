cmake_minimum_required(VERSION 3.0.0)
project(a03 VERSION 0.1.0)

set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT MSVC)
	add_compile_options(-Wall)
	add_compile_options(-pedantic)
endif(NOT MSVC)

add_executable(a03 main.cpp utils.cpp utils.hpp)
