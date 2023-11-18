cmake_minimum_required(VERSION 3.26)
project(Verifica_login_e_senha_utilizando_lista C)

set(CMAKE_C_STANDARD 11)

include_directories(libprg)

add_executable(Verifica_login_e_senha_utilizando_lista
        libprg/listaencadeada.c
        libprg/listaencadeada.h
        projeto_login.c)
