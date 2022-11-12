template <class E>
class SortingAlgorithms {

public:

    static void selectionSort( E* array , int size ) ;
    static void bubbleSort( E* array , int size ) ;

} ;

template <class E>
void SortingAlgorithms<E>::selectionSort( E* array, int size) {
    for( int i = 0 ; i < size ; i++ ) {
        E minElement = *( array + i ) ; // ith element
        for( int j = 0 ; j < size ; j++ ) {
            if( minElement > *( array + j ) ) {
                minElement = *( array +  j ) ; // jth element
            }
        }
        ( array + i ) = &minElement ;
    }
}