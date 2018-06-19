cmake_minimum_required(VERSION 3.9)
project(Compilerbau C)

set(CMAKE_C_STANDARD 99)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -pedantic")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_executable(handparser Assignment3/handparser/minako-syntax.c Assignment3/handparser/minako.h Assignment3/handparser/minako-lexic.c)
