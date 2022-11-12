#include <iostream>

template <class E>
class DoublyLinkedList {

private:

    // Node structure
    struct Node {
        // Value that the node contains
        E value ;
        // Pointer to the next node in the list
        Node* pointerToNext = nullptr;
        Node* pointerToPrev = nullptr ;
    } ;

    Node* HEAD_FRONT ;
    Node* HEAD_BACK ;
    int numElements ;

public:

    DoublyLinkedList() ;
    ~DoublyLinkedList() ;
    void insertFront( E element ) ;
    void insertBack( E element ) ;
    void printForward() ;
    void printBackward() ;
    void clear() ;

};

template <class E>
DoublyLinkedList<E>::DoublyLinkedList() {
    HEAD_FRONT = nullptr ;
    HEAD_BACK = nullptr ;
    numElements = 0 ;
}

template <class E>
DoublyLinkedList<E>::~DoublyLinkedList() {
    clear() ;
}

template <class E>
void DoublyLinkedList<E>::insertFront(E element) {
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
void DoublyLinkedList<E>::printForward() {
    Node* currentNode = HEAD_BACK ;
    for ( int i = 0 ; i < numElements ; i ++ ) {
        std::cout << currentNode -> value << std::endl ;
        currentNode = currentNode -> pointerToNext ;
    }
}

template <class E>
void DoublyLinkedList<E>::printBackward() {
    Node* currentNode = HEAD_FRONT ;
    for ( int i = 0 ; i < numElements ; i ++ ) {
        std::cout << currentNode -> value << " " ;
        currentNode = currentNode -> pointerToPrev ;
    }
}

template <class E>
void DoublyLinkedList<E>::clear() {
    // Delete all dynamically allocated nodes to free up memory
    Node* currentNode = HEAD_BACK ;
    for ( int i = 0 ; i < numElements ; i ++ ) {
        Node* nextNode = currentNode -> pointerToNext ;
        delete currentNode ;
        currentNode = nextNode ;
    }
    numElements = 0 ;
    HEAD_FRONT = nullptr ;
    HEAD_BACK = nullptr ;
}
