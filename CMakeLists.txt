cmake_minimum_required(VERSION 3.23)
project(DSA)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        DSA
        main.cpp
        # LinkedList
        02_linkedlist/linkedlist.h
        02_linkedlist/linkedlist.cpp
        02_linkedlist/circular_linkedlist.h
        02_linkedlist/circular_linkedlist.cpp
        02_linkedlist/doubly_linkedlist.h
        02_linkedlist/doubly_linkedlist.cpp
        # Stack
        03_stack/stack.h
        03_stack/stack.cpp
        # Sorting Algorithms
        sorting_algorithms/sorting_algorithm.h
        sorting_algorithms/selection_sort.h
        # Polynomials
        # polynomials/polynomial.h
        # polynomials/polynomial.cpp
)
