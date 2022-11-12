#include "linkedlist_singly.cpp"
#include <iostream>

template <class E>
class Stack {

private:
    E* HEAD ;
    int size ;

    int* elements;

public:

    Stack( int initSize ) ;

    void push( E element ) ;
    E pop() ;

};

template <class E>
Stack<E>::Stack(int initSize ) {
    size = initSize ;
    HEAD = -1 ;
    elements = new int[ size ]  ;
}

template <class E>
void Stack<E>::push(E element) {
    if( HEAD == size - 1 ){
        std::cout << "Stack overflow occurred \n" ;
    }
    else {
        HEAD++ ;
        int* elementAddress = elements + ( HEAD * sizeof( int ) ) ;
        elementAddress = &element ;
    }
}

template <class E>
E Stack<E>::pop() {
    if ( HEAD == -1 ) {
        std::cout << "Stack is empty \n" ;
    }
    else {
        HEAD-- ;
    }
}