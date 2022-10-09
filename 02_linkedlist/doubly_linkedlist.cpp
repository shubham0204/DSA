#include "doubly_linkedlist.h"
#include <iostream>

void DoublyLinkedList::insertFront(int element) {
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

void DoublyLinkedList::insertBack(int element) {
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

void DoublyLinkedList::print() {
    Node* currentNode = HEAD_BACK ;
    for ( int i = 0 ; i < numElements ; i ++ ) {
        std::cout << currentNode -> value << std::endl ;
        currentNode = currentNode -> pointerToNext ;
    }
}

DoublyLinkedList::DoublyLinkedList() {
    HEAD_FRONT = nullptr ;
    HEAD_BACK = nullptr ;
    numElements = 0 ;
}
