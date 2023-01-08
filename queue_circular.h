#ifndef DSA_QUEUE_CIRCULAR_H
#define DSA_QUEUE_CIRCULAR_H

#include <iostream>

template <class E>
class CircularQueue {

    int capacity ;
    int numElements ;
    E* elements ;
    int FRONT ;
    int REAR ;

public:

    explicit CircularQueue( int capacity ) ;
    ~CircularQueue() ;
    void push( E element ) ;
    bool isEmpty() ;
    bool isFull() ;
    void print() ;
    E pop() ;

} ;

template <class E>
CircularQueue<E>::CircularQueue( int capacity ){
    this -> capacity = capacity ;
    elements = new E[ capacity ] ;
    this -> numElements = 0 ;
    this -> FRONT = -1 ;
    this -> REAR = -1 ;
}

template <class E>
CircularQueue<E>::~CircularQueue(){
    delete elements ;
}

template <class E>
void CircularQueue<E>::push( E element ) {
    if( numElements == 0 ) {
        FRONT = REAR = 0 ;
    }
    else {
        REAR = ( REAR + 1 ) % capacity ;
    }
    elements[ REAR ] = element ;
    numElements++ ;
}

template <class E>
E CircularQueue<E>::pop() {
    numElements-- ;
    E poppedElement = elements[ FRONT ] ;
    FRONT = ( FRONT + 1 ) % capacity ;
    return poppedElement ;
}

template <class E>
bool CircularQueue<E>::isEmpty() {
    return numElements == 0 ;
}

template <class E>
bool CircularQueue<E>::isFull() {
    return numElements == capacity ;
}

template <class E>
void CircularQueue<E>::print() {
    for( int i = FRONT ; i <= REAR ; i++ ) {
        std::cout << elements[ i ] << " " ;
    }
    std::cout << "\n" ;
}

#endif //DSA_QUEUE_CIRCULAR_H
