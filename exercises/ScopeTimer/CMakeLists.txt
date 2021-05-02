cmake_minimum_required(VERSION 3.20.1)
project("ScopeTimer")

set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT MSVC)
	add_compile_options(-Wall)
	add_compile_options(-Wextra)
	add_compile_options(-pedantic)
endif(NOT MSVC)

add_executable(main.cpp scopetimer.cpp scopetimer.hpp)
