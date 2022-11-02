#include "doubly_linkedlist.h"
#include <iostream>

template <class E>
void DoublyLinkedList<E>::insertFront(int element) {
    if ( numElements == 0 ) {
        HEAD_FRONT = new( Node ) ;
        HEAD_FRONT -> value = element ;
        HEAD_BACK = HEAD_FRONT;
    }
    else {
        Node* headNode = HEAD_FRONT ;
        Node* nextNode = new( Node ) ;
        nextNode -> value = element ;
        nextNode -> pointerToPrev = headNode ;
        headNode -> pointerToNext = nextNode ;
        HEAD_FRONT = nextNode ;
    }
    numElements += 1 ;
}

template <class E>
void DoublyLinkedList<E>::insertBack(E element) {
    if ( numElements == 0 ) {
        HEAD_FRONT = new( Node ) ;
        HEAD_FRONT -> value = element ;
        HEAD_BACK = HEAD_FRONT;
    }
    else {
        Node* headNode = HEAD_BACK ;
        Node* nextNode = new( Node ) ;
        nextNode -> value = element ;
        nextNode -> pointerToNext = headNode ;
        headNode -> pointerToPrev = nextNode ;
        HEAD_BACK = nextNode ;
    }
    numElements += 1 ;
}

template <class E>
void DoublyLinkedList<E>::print() {
    Node* currentNode = HEAD_BACK ;
    for ( int i = 0 ; i < numElements ; i ++ ) {
        std::cout << currentNode -> value << std::endl ;
        currentNode = currentNode -> pointerToNext ;
    }
}

template <class E>
DoublyLinkedList<E>::DoublyLinkedList() {
    HEAD_FRONT = nullptr ;
    HEAD_BACK = nullptr ;
    numElements = 0 ;
}
