#ifndef DSA_DOUBLY_LINKEDLIST_H
#define DSA_DOUBLY_LINKEDLIST_H

#include "linkedlist.h"

class DoublyLinkedList {

private:

    // Node structure
    struct Node {
        // Value that the node contains
        int value ;
        // Pointer to the next node in the list
        Node* pointerToNext = nullptr;
        Node* pointerToPrev = nullptr ;
    } ;

    Node* HEAD_FRONT ;
    Node* HEAD_BACK ;
    int numElements ;

public:

    DoublyLinkedList() ;
    void insertFront( int element ) ;
    void insertBack( int element ) ;
    void print() ;

};

#endif //DSA_DOUBLY_LINKEDLIST_H
