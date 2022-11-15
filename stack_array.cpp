#include "linkedlist_singly.cpp"
#include <iostream>

template <class E>
class Stack {

private:
    E* HEAD ;
    int size ;
    E* elements;

public:

    Stack( int capacity ) ;

    void push( E element ) ;
    E pop() ;

};

template <class E>
Stack<E>::Stack( int capacity ) {
    size = capacity ;
    HEAD = -1 ;
    elements = new E[ size ]  ;
}

template <class E>
void Stack<E>::push(E element) {
    if( HEAD == size - 1 ){
        std::cout << "Stack overflow occurred \n" ;
    }
    else {
        HEAD++ ;
        int* elementAddress = elements + HEAD ;
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