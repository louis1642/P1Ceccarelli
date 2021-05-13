cmake_minimum_required(VERSION 3.19)
project(GenericLinkedList)

set(CMAKE_CXX_STANDARD 11)

add_executable(GenericLinkedList main.cpp Node.h LinkedList.cpp LinkedList.h)