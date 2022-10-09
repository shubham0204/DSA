#include "stack.h"
#include <iostream>

Stack::Stack(int initSize , bool useLinkedList ) {
    size = initSize ;
    HEAD = -1 ;
    useList = useLinkedList ;
    elements = new int[ size ]  ;
}

void Stack::push(int element) {
    if( HEAD == size - 1 ){
        std::cout << "Stack overflow occurred \n" ;
    }
    else {
        HEAD++ ;
        if ( useList ) {
            linkedList.add( element ) ;
        }
        else {
            int* elementAddress = elements + ( HEAD * sizeof( int ) ) ;
            elementAddress = &element ;
        }
    }
}

int Stack::pop() {
    if ( HEAD == -1 ) {
        std::cout << "Stack is empty \n" ;
    }
    else {
        HEAD-- ;
        if ( useList ) {

        }
        else {

        }
    }
}