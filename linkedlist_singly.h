#ifndef DSA_LINKEDLIST_SINGLY_H
#define DSA_LINKEDLIST_SINGLY_H
#include <iostream>
/*
 * Implementation of a simple Linked List
 * -> Linked List is a linear data structure similar to an array, but elements are not placed
 * in consecutive memory locations and has NUMA.
 */
template <class E>
class LinkedList {

    struct Node {
        // A structure that holds the value of the element E and the pointer that stores the
        // address of the next element
        E value ;
        Node* pointerToNext = nullptr;
    } ;
    Node* START ; // Pointer to Node representing the start of the list
    Node* HEAD ;  // Pointer to Node representing the last element of the list
    int numElements = 0 ;

public:
    LinkedList() = default;
    ~LinkedList() ;
    void insertFront(E element ) ; // Add element after HEAD
    void insertBack(E element) ;   // Add element before START
    void insertAt(E element , int index ) ; // Add element in between the list at `index`
    E get( int index ) ; // Retrieve the element at `index` from the linkedlist
    void deleteByValue( E value ) ;    // Deletes the element by checking its value
    void deleteByIndex( int index ) ;  // Deletes the element by checking its index
    void print() ;  // Print the linkedlist
    void clear() ;  // Delete all nodes from the linkedlist
} ;

/*
 * In the destructor, call `clear` method that deletes all `Node` objects
 * which were allocated memory dynamically
 */
template <class E>
LinkedList<E>::~LinkedList() {
    // When this object is destructed, free all the nodes
    clear() ;
}

/*
 * Add the element after HEAD. It is a constant time operation.
 */
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

/*
 * Add the element before START. It is a constant time operation.
 */
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

/*
 * Add element E at `index`. It is a constant time operation.
 */
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

/*/
 * Retrieves the value of the node at `index`. This is a O( N ) operation as it includes list traversal.
 */
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

/*
 * Deletes the node present at `index`. It is a O( N ) operation as it includes list traversal.
 */
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

/*
 * Deletes the node with given `value`. It is a O( N ) operation as it includes list traversal.
 */
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

/*
 * Print all elements of the list. It is a O( N ) operation as we're travelling the list.
 */
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


#endif //DSA_LINKEDLIST_SINGLY_H
