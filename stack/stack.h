#include <iostream>
#include "../02_linkedlist/linkedlist.h"

template <class E>
class Stack {

private:
    E* HEAD ;
    int size ;
    bool useList ;

    int* elements;
    LinkedList<E> linkedList ;

public:

    Stack( int initSize , bool useLinkedList = true ) ;

    void push( E element ) ;
    int pop() ;

};