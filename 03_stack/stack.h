#include <iostream>
#include "../02_linkedlist/linkedlist.h"

class Stack {

private:
    int HEAD ;
    int size ;
    bool useList ;

    int* elements;
    LinkedList linkedList ;

public:

    Stack( int initSize , bool useLinkedList = true ) ;

    void push( int element ) ;
    int pop() ;

};