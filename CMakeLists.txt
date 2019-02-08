cmake_minimum_required(VERSION 3.12)
project(LinkedLists)

set(CMAKE_CXX_STANDARD 14)

add_executable(LinkedLists src/LinkedList.c src/LinkedList.h main.c tests/minunit.h tests/LinkedListTest.c)