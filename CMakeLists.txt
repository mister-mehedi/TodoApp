cmake_minimum_required(VERSION 3.19)
project(TodoApp)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(TodoApp
        include/Task.h
        include/TodoApp.h
        src/Task.cpp
        src/TodoApp.cpp
        main.cpp)
