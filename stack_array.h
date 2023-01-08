#ifndef DSA_STACK_ARRAY_H
#define DSA_STACK_ARRAY_H
#include <iostream>


template <class E>
class StackArray {

private:
    int HEAD_INDEX;
    E *elements;
    int numElements;
    int capacity;

public:

    explicit StackArray(int capacity) ;
    ~StackArray() ;
    void push(E element);
    void print() ;
    void pop() ;
    int getNumElements();
    E head() ;
    bool isEmpty() ;
    bool isFull() ;
    bool contains( E element ) ;

};

template <class E>
StackArray<E>::StackArray(int capacity ) {
    this -> numElements = 0;
    this -> capacity = capacity;
    this -> elements = new E[capacity];
    this -> numElements = 0 ;
    this -> HEAD_INDEX = -1 ;
}


template <class E>
void StackArray<E>::push(E element) {
    if( !isFull() ) {
        elements[ ++HEAD_INDEX ] = element;
        numElements++ ;
    }
    else {
        std::cout << "StackArray is full." << "\n" ;
    }
}

template <class E>
void StackArray<E>::pop() {
    if ( !isEmpty() ) {
        HEAD_INDEX-- ;
        numElements-- ;
    }
    else {
        std::cout << "StackArray is empty." << "\n" ;
    }
}

template <class E>
void StackArray<E>::print() {
    for (int i = 0; i < numElements ; i++ ) {
        std::cout << elements[ i ] << "\n";
    }
}

template<class E>
int StackArray<E>::getNumElements() {
    return numElements ;
}

template<class E>
E StackArray<E>::head() {
    return elements[ HEAD_INDEX ];
}

template<class E>
StackArray<E>::~StackArray() {
    delete elements ;
}

template<class E>
bool StackArray<E>::isEmpty() {
    return numElements == 0;
}

template<class E>
bool StackArray<E>::isFull() {
    return numElements == capacity;
}

template<class E>
bool StackArray<E>::contains(E element ) {
    for (int i = numElements - 1; i > -1; i--) {
        if( elements[i] == element ) {
            return true ;
        }
    }
    return false ;
}

#endif //DSA_STACK_ARRAY_H
