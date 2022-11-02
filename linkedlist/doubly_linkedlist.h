#ifndef DSA_DOUBLY_LINKEDLIST_H
#define DSA_DOUBLY_LINKEDLIST_H

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
    void insertFront( E element ) ;
    void insertBack( E element ) ;
    void print() ;

};

#endif //DSA_DOUBLY_LINKEDLIST_H
