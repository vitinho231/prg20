cmake_minimum_required(VERSION 3.26)
project(prg029003 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(aula19-09/libprg/src/include)
include_directories(aula19-09/libprg/src/include/libprg)

add_executable(prg029003
        aula19-09/libprg/src/include/libprg/libprg.h
        aula19-09/libprg/src/libprg/libprg.c
        aula19-09/libprg/src/libprg/sub.c
        aula19-09/libprg/src/libprg/sum.c
        aula19-09/main.c
        "tarefa 1/tarefa.c"
        "tarefa 2/tarefa 2.c"
        "tarefa 3/tarefa 3.c"
        "tarefa-4 algoritmos quicksort/tarefa 4.c")
