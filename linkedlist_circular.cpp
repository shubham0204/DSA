// CircularLinkedList Implementation
template <class E>
class CircularLinkedList {

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
    int numElements;

public:

    CircularLinkedList() ;
    void insertFront(E element ) ;

} ;

template <class E>
CircularLinkedList<E>::CircularLinkedList() {
    START = nullptr ;
    HEAD = nullptr ;
    numElements = 0 ;
}

template <class E>
void CircularLinkedList<E>::insertFront( E element ) {
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
        headNode -> pointerToNext = CircularLinkedList<E>::START ;
    }
    numElements += 1 ;
}