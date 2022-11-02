cmake_minimum_required(VERSION 3.23)
project(DSA)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        DSA
        main.cpp
        # LinkedList
        linkedlist/linkedlist.h
        linkedlist/linkedlist.cpp
        linkedlist/circular_linkedlist.h
        linkedlist/circular_linkedlist.cpp
        linkedlist/doubly_linkedlist.h
        linkedlist/doubly_linkedlist.cpp
        # Stack
        stack/stack.h
        stack/stack.cpp
        # Sorting Algorithms
        sorting/sorting_algorithm.h
        sorting/selection_sort.h
        sorting/selection_sort.cpp
        # Polynomials
        # polynomials/polynomial.h
        # polynomials/polynomial.cpp
)
