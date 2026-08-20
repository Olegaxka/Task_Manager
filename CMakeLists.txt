cmake_minimum_required(VERSION 3.20)

project(Task_Manager)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Task_Manager
src/main.cpp
src/Task.cpp
src/TaskManager.cpp
)
