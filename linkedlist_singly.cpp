#include <iostream>

// LinkedList implementation
template <class E>
class LinkedList {

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

template <class E>
LinkedList<E>::~LinkedList() {
    // When this object is destructed, free all the nodes
    clear() ;
}

template <class E>
void LinkedList<E>::insertFront( E element ) {
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
        headNode -> pointerToNext = nextNode ;
        HEAD = nextNode ;
    }
    numElements += 1 ;
}

template <class E>
void LinkedList<E>::insertBack(E element) {
    if ( numElements == 0 ) {
        START = new( Node ) ;
        START -> value = element ;
        HEAD = START;
    }
    else {
        Node* headNode = START ;
        Node* nextNode = new( Node ) ;
        nextNode -> value = element ;
        nextNode -> pointerToNext = headNode ;
        START = nextNode ;
    }
    numElements += 1 ;
}

template <class E>
void LinkedList<E>::insertAt(E element, int index) {
    Node* currentNode = START ;
    for ( int i = 0 ; i < index ; i ++ ) {
        currentNode = currentNode -> pointerToNext ;
    }
    Node* newNode = new( Node ) ;
    newNode -> value = element ;
    newNode -> pointerToNext = currentNode -> pointerToNext ;
    currentNode -> pointerToNext = newNode ;
    numElements += 1 ;
}

template <class E>
E LinkedList<E>::get( int index ) {
    Node* currentNode = START ;
    for ( int i = 0 ; i < numElements ; i ++ ) {
        if( index == i ) {
            return currentNode -> value ;
        }
        currentNode = currentNode -> pointerToNext ;
    }
    return -1 ;
}

template <class E>
void LinkedList<E>::deleteByIndex( int index ) {
    // kth Node in the LinkedList
    Node* prevNode = START ;

    // (k+1)th Node in the LinkedList
    Node* currentNode = START ;

    for ( int i = 0 ; i < numElements ; i ++ ) {
        // Checking if value == currentNode's value
        if ( i == index ) {
            if( i == 0 ) {
                // Delete first element START of the LinkedList
                // and reassign it
                START = START -> pointerToNext ;
            }
            else if ( i == numElements - 1 ) {
                // Delete last element HEAD of the LinkedList
                // and reassign it
                delete HEAD ;
                HEAD = new( Node ) ;
                HEAD = prevNode ;
            }
            else {
                prevNode -> pointerToNext = currentNode -> pointerToNext ;
            }
            numElements -= 1 ;
            break;
        }
        prevNode = currentNode ;
        currentNode = currentNode -> pointerToNext ;
    }
}

template <class E>
void LinkedList<E>::deleteByValue( E value ) {
    // kth Node in the LinkedList
    Node* prevNode = START ;

    // (k+1)th Node in the LinkedList
    Node* currentNode = START ;

    for ( int i = 0 ; i < numElements ; i ++ ) {
        // Checking if value == currentNode's value
        if ( (currentNode -> value) == value ) {
            if( i == 0 ) {
                // Delete first element START of the LinkedList
                // and reassign it
                START = START -> pointerToNext ;
            }
            else if ( i == numElements - 1 ) {
                // Delete last element HEAD of the LinkedList
                // and reassign it
                delete HEAD ;
                HEAD = new( Node ) ;
                HEAD = prevNode ;
            }
            else {
                prevNode -> pointerToNext = currentNode -> pointerToNext ;
            }
            numElements -= 1 ;
            break;
        }
        prevNode = currentNode ;
        currentNode = currentNode -> pointerToNext ;
    }
}

template <class E>
void LinkedList<E>::print() {
    Node* currentNode = START ;
    for ( int i = 0 ; i < numElements ; i ++ ) {
        std::cout << currentNode -> value << std::endl ;
        currentNode = currentNode -> pointerToNext ;
    }
}

template <class E>
void LinkedList<E>::clear() {
    // Delete all dynamically allocated nodes to free up memory
    Node* currentNode = START ;
    for ( int i = 0 ; i < numElements ; i ++ ) {
        Node* nextNode = currentNode -> pointerToNext ;
        delete currentNode ;
        currentNode = nextNode ;
    }
    numElements = 0 ;
    START = nullptr ;
    HEAD = nullptr ;
}



