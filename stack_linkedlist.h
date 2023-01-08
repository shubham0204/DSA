#ifndef DSA_STACK_LINKEDLIST_H
#define DSA_STACK_LINKEDLIST_H

#include <iostream>

template <class E>
class StackLinkedList {

private:

    struct Node {
        E val ;
        Node* next ;
        Node* prev ;
    };
    Node* HEAD ;
    Node* START ;
    int numElements ;
    int capacity ;

public:

    explicit StackLinkedList(int capacity);
    ~StackLinkedList() ;
    void push( E element ) ;
    void print() ;
    bool isFull() ;
    bool isEmpty() ;
    void pop() ;
    E head() ;
    int getNumElements();

};

template<class E>
StackLinkedList<E>::StackLinkedList(int capacity) {
    this -> numElements = 0;
    this -> capacity = capacity;
    this -> HEAD = nullptr ;
    this -> START = nullptr ;
}

template<class E>
void StackLinkedList<E>::push(E element) {
    Node* newNode = new( Node ) ;
    newNode -> val = element ;
    newNode -> next = nullptr ;
    if( numElements == 0 ){
        HEAD = START = newNode ;
        newNode -> prev = nullptr ;
    }
    else {
        HEAD -> next = newNode ;
        newNode -> prev = HEAD ;
        HEAD = newNode ;
    }
    numElements++ ;
}

template<class E>
void StackLinkedList<E>::print() {
    Node* currentNode = START ;
    while( currentNode != nullptr ) {
        std::cout << currentNode -> val << " " ;
        currentNode = currentNode -> next ;
    }
    std::cout << "\n" ;
}

template<class E>
void StackLinkedList<E>::pop() {
    if( !isEmpty() ) {
        Node* prevNode = HEAD -> prev ;
        prevNode -> next = nullptr ;
        delete HEAD ;
        HEAD = prevNode ;
        numElements-- ;
    }
}

template<class E>
int StackLinkedList<E>::getNumElements() {
    return numElements ;
}

template<class E>
bool StackLinkedList<E>::isFull() {
    return numElements == capacity ;
}

template<class E>
bool StackLinkedList<E>::isEmpty() {
    return numElements == 0 ;
}

template<class E>
StackLinkedList<E>::~StackLinkedList() {
    Node* currentNode = START ;
    while( currentNode != nullptr ) {
        Node* nextNode = currentNode -> next ;
        delete currentNode ;
        currentNode = nextNode ;
    }
}

template<class E>
E StackLinkedList<E>::head() {
    return *HEAD ;
}

#endif //DSA_STACK_LINKEDLIST_H
