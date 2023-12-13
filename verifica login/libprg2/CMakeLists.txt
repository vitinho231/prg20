cmake_minimum_required(VERSION 3.26)
project(libprg2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(libprg2
        fila.c
)
