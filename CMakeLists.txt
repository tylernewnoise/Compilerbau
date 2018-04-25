cmake_minimum_required(VERSION 3.9)
project(Compilerbau C)

set(CMAKE_C_STANDARD 99)

add_executable(Stack Assignment1/teststack.c Assignment1/stack.h Assignment1/stack.c)
add_executable(Syntree Assignment1/testsyntree.c Assignment1/syntree.h Assignment1/syntree.c)
