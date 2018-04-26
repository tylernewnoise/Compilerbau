cmake_minimum_required(VERSION 3.9)
project(Compilerbau C)

set(CMAKE_C_STANDARD 99)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -pedantic")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_executable(Stack Assignment1/teststack.c Assignment1/stack.c)
add_executable(Syntree Assignment1/testsyntree.c Assignment1/syntree.c)
