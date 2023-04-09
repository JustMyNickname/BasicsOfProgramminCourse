cmake_minimum_required(VERSION 3.25)
project(GithubProject C)

set(CMAKE_C_STANDARD 11)

add_executable(GithubProject main.c)

add_library(data_structures

        libs/data_structures/vector/vector.h
        libs/data_structures/vector/vector.c)

target_link_libraries(GithubProject data_structures)