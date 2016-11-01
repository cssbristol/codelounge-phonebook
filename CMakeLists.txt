cmake_minimum_required(VERSION 3.6)
project(codelounge_phonebook)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    phonebook.c)

add_executable(codelounge_phonebook ${SOURCE_FILES})