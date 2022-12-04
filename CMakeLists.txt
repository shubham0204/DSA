cmake_minimum_required(VERSION 3.23)

set(CMAKE_CXX_STANDARD 14)
project(DSA)

set( SOURCES
        main.cpp
        linkedlist_singly.h
        linkedlist_circular.h
        linkedlist_doubly.h
        stack_array.h
        stack_linkedlist.h
        sorting_algorithms.h
        searching_algorithms.h
        # includes/expression_infix2postfix.h

        # linkedlist_singly.cpp
        # linkedlist_circular.cpp
        # linkedlist_doubly.cpp
        # stack_array.cpp
        # stack_linkedlist.cpp
        # sorting_algorithms.cpp
        # searching_algorithms.cpp
        # expression_infix2postfix.cpp
)


add_executable( DSA ${SOURCES} )


