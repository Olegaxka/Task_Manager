# Task Manager

A console-based C++ project for learning and practicing modern C++ and STL.

The project implements a simple task management application with task creation, searching, modification, deletion, sorting and statistics.

## Features

* Create tasks with automatically generated IDs
* Store tasks in `std::vector`
* Find tasks by ID
* Remove tasks by ID
* Change task status
* Change task priority
* Display all tasks
* Sort tasks by priority
* Search and filter tasks
* Calculate task statistics

## STL Practice

The project was used to practice:

* Iterators
* Const and reverse iterators
* Lambda expressions
* STL algorithms
* `std::find_if`
* `std::remove_if`
* `std::sort`
* `std::stable_sort`
* `std::count_if`
* `std::all_of`
* `std::any_of`
* `std::none_of`
* `std::for_each`
* `std::transform`
* `std::accumulate`
* `std::copy_if`
* `std::min_element`
* `std::max_element`
* `std::binary_search`
* `std::lower_bound`

## Technologies

* C++20
* STL
* CMake
* Visual Studio
* Git

## Project Structure

```text
Task_Manager/
├── src/
│   ├── main.cpp
│   ├── Task.h
│   ├── Task.cpp
│   ├── TaskManager.h
│   └── TaskManager.cpp
├── CMakeLists.txt
├── .gitignore
└── README.md
```

## Build

The project uses CMake 3.20 or newer.

```bash
cmake -S . -B build
cmake --build build
```

## Current Status

The project is completed as a learning and portfolio project.

The main goal of the project was to gain practical experience with C++20, STL containers, iterators, algorithms, lambdas and basic console application design.

Tasks are currently stored in memory and are not saved after the application is closed.
