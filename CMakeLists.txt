cmake_minimum_required(VERSION 3.23)

set(CMAKE_CXX_STANDARD 14)

project(DSA)

add_executable(
        DSA
        main.cpp

        # LinkedList
        linkedlist_singly.cpp
        linkedlist_circular.cpp
        linkedlist_doubly.cpp

        # Stack
        stack_array.cpp

        # Sorting Algorithms
        sorting_algorithms.cpp

        # Searching Algorithms
        searching_algorithms.cpp

        # Polynomials
        # polynomials/polynomial.h
        # polynomials/polynomial.cpp
)

