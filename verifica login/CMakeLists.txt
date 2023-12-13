cmake_minimum_required(VERSION 3.26)
project(verifica_login C)

set(CMAKE_C_STANDARD 11)

add_executable(verifica_login login_projeto.c libprg2/listaencadeada.c libprg2/listaencadeada.h)

# Adicione o diretório da biblioteca
target_include_directories(verifica_login PRIVATE libprg2)
