cmake_minimum_required(VERSION 3.26)
project(Verifica_login_e_senha_utilizando_tabela_hash C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Verifica_login_e_senha_utilizando_tabela_hash
        login_hash.c)
