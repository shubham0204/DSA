#ifndef DSA_STACK_ARRAY_H
#define DSA_STACK_ARRAY_H
#include <iostream>

template <class E>
class Stack {

private:
    int HEAD_INDEX;
    E *elements;
    int numElements;
    int capacity;

public:

    Stack(int capacity) ;
    ~Stack() ;
    void push(E element);
    void print() ;
    E pop() ;
    int getNumElements();
    E head() ;
    bool isEmpty() ;
    bool isFull() ;
    bool contains( E element ) ;

};

template <class E>
Stack<E>::Stack( int capacity ) {
    // Initialize array
    this -> numElements = 0;
    this -> capacity = capacity;
    elements = new E[capacity];
    HEAD_INDEX = -1 ;
}


template <class E>
void Stack<E>::push(E element) {
    if( numElements != capacity ) {
        *(elements + ++HEAD_INDEX) = element;
        numElements += 1;
    }
    else {
        std::cout << "Stack is full." << "\n" ;
    }
}

template <class E>
E Stack<E>::pop() {
    if (numElements > 0) {
        HEAD_INDEX -= 1;
        numElements -= 1;
        return *(elements + HEAD_INDEX + 1) ;
    }
    else {
        return NULL ;
    }
}

template <class E>
void Stack<E>::print() {
    for (int i = numElements - 1; i > -1; i--) {
        std::cout << *(elements + i) << "\n";
    }
}

template<class E>
int Stack<E>::getNumElements() {
    return numElements ;
}

template<class E>
E Stack<E>::head() {
    return *( elements + HEAD_INDEX ) ;
}

template<class E>
Stack<E>::~Stack() {
    delete elements ;
}

template<class E>
bool Stack<E>::isEmpty() {
    return HEAD_INDEX == -1;
}

template<class E>
bool Stack<E>::isFull() {
    return HEAD_INDEX == capacity - 1;
}

template<class E>
bool Stack<E>::contains( E element ) {
    for (int i = numElements - 1; i > -1; i--) {
        if( *(elements + i) == element ) {
            return true ;
        }
    }
    return false ;
}

#endif //DSA_STACK_ARRAY_H
