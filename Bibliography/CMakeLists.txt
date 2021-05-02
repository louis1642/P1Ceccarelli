cmake_minimum_required(VERSION 3.19)
project(Bibliography)

set(CMAKE_CXX_STANDARD 11)

add_executable(Bibliography main.cpp Publication.cpp Publication.h Book.cpp Book.h PaperArticle.cpp PaperArticle.h ConferenceArticle.cpp ConferenceArticle.h QuickSort.cpp QuickSort.h)