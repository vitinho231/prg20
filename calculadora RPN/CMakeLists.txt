cmake_minimum_required(VERSION 3.26)
project(calculadora_RPN C)

set(CMAKE_C_STANDARD 11)

include_directories(include)
include_directories(include/libprg2)

add_executable(calculadora_RPN
        include/libprg2/libprg2.h
        include/RPN.c
        include/libprg2/Pilha.c
)
