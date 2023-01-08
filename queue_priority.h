#ifndef DSA_QUEUE_PRIORITY_H
#define DSA_QUEUE_PRIORITY_H

#include <iostream>

template <class E>
class PriorityQueue {

    struct Node {
        E val ;
        Node* next ;
        int priority ;
    } ;
    Node* FRONT ;
    Node* REAR ;
    int numElements ;
    int capacity ;

public:

    PriorityQueue( int capacity ) ;
    void push( E element ) ;
    E pop() ;
    bool isEmpty() ;
    bool isFull() ;
    void print() ;

} ;

template <class E>
PriorityQueue<E>::PriorityQueue( int capacity ) {
    this -> capacity = capacity ;
    this -> FRONT = nullptr ;
    this -> REAR = nullptr ;
    this -> numElements = 0 ;
}

template <class E>
void PriorityQueue<E>::push( E element , int priority ) {
    Node* newNode = new( Node ) ;
    newNode -> val = element ;
    newNode -> priority = priority ;
    if( numElements == 0 ) {
        newNode -> next = nullptr ;
        FRONT = REAR = newNode ;
    }
    else {
        if( priority > FRONT -> priority ) {
            newNode -> next = FRONT ;
            FRONT = newNode ;
        }
        else if( priority < REAR -> priority ) {
            newNode -> next = nullptr ;
            REAR -> next = newNode ;
            REAR = newNode ;
        }
        else {
            Node* currentNode = FRONT ;
            while( currentNode -> next != nullptr ) {
                if( currentNode -> next -> priority < priority ) {
                    newNode -> next = currentNode -> next ;
                    currentNode -> next = newNode ;
                    break;
                }
                currentNode = currentNode -> next ;
            }
        }
    }
    numElements++ ;
}

template <class E>
E PriorityQueue<E>::pop() {
    E poppedElement = *FRONT ;
    Node* secondNode = FRONT -> next ;
    delete FRONT ;
    FRONT = secondNode ;
    numElements-- ;
    return poppedElement;
}

template <class E>
bool PriorityQueue<E>::isEmpty() {
    return numElements == 0 ;
}

template <class E>
bool PriorityQueue<E>::isFull() {
    return numElements == capacity ;
}

template <class E>
void PriorityQueue<E>::print() {
    Node* currentNode = FRONT ;
    while( currentNode != nullptr ) {
        cout << currentNode -> val << " " ;
        currentNode = currentNode -> next ;
    }
    cout << "\n" ;
}

#endif //DSA_QUEUE_PRIORITY_H
