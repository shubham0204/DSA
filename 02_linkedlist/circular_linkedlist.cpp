#include "circular_linkedlist.h"

void CircularLinkedList::add( int element ) {
    if ( numElements == 0 ) {
        // If the list was empty, initialize START and HEAD
        START = new( Node ) ;
        START -> value = element ;
        HEAD = START;
    }
    else {
        // Else, update HEAD
        Node* headNode = HEAD ;
        Node* nextNode = new( Node ) ;
        nextNode -> value = element ;
        headNode -> pointerToNext = START ;
    }
    numElements += 1 ;
}