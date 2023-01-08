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

        sparse_matrix_array.cpp

        expression_valid_parenthesis.cpp

        queue_circular.h
        queue_priority.h

)

add_library( DSA SHARED ${SOURCES} )


