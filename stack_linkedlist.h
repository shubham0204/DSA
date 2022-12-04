#ifndef DSA_STACK_LINKEDLIST_H
#define DSA_STACK_LINKEDLIST_H

#include "linkedlist_singly.h"

template <class E>
class Stack {

private:
    int HEAD_INDEX;
    LinkedList<E> list ;
    int numElements;
    int capacity;

public:

    Stack(int capacity);
    void push(E element);
    void print();
    void pop();
    int getNumElements();

};

template<class E>
Stack<E>::Stack(int capacity) {
    // Initialize array
    this -> numElements = 0;
    this -> capacity = capacity;
}

template<class E>
void Stack<E>::push(E element) {
    if (numElements == 0){
        HEAD_INDEX = 0;
    }
    else{
        HEAD_INDEX++;
    }
    list.insertFront( element ) ;
    numElements += 1;
}

template<class E>
void Stack<E>::print() {
    list.print() ;
}

template<class E>
void Stack<E>::pop() {
    if (numElements > 0) {
        numElements -= 1;
        list.deleteByIndex( HEAD_INDEX ) ;
        HEAD_INDEX -= 1;
    }
}

template<class E>
int Stack<E>::getNumElements() {
    return numElements ;
}

#endif //DSA_STACK_LINKEDLIST_H
