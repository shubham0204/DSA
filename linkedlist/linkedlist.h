#ifndef DSA_LINKEDLIST_H
#define DSA_LINKEDLIST_H

#include <iostream>

// LinkedList implementation
template <class E>
class LinkedList {

protected:

    // Node structure
    struct Node {
        // Value that the node contains
        E value ;
        // Pointer to the next node in the list
        Node* pointerToNext = nullptr;
    } ;

    // Pointer to Node representing the start of the list
    Node* START ;
    // Pointer to Node representing the last element of the list
    Node* HEAD ;
    int numElements = 0 ;

public:

    LinkedList(){}
    ~LinkedList() ;

    void insertFront(E element ) ;
    void insertBack(E element) ;
    void insertAt(E element , int index ) ;
    E get( int index ) ;
    void deleteByValue( E value ) ;
    void deleteByIndex( int index ) ;
    void print() ;
    void clear() ;
} ;

#endif //DSA_LINKEDLIST_H
