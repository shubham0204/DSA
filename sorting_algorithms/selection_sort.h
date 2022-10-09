#include <iostream>
#include "sorting_algorithm.h"
using namespace std ; 

class SelectionSort : public SortingAlgorithm {

    private:
    int* getElement( int* baseAddress , int index ) ;

    public:

    SelectionSort(){};
    int* sort( int* array , int size ) ;

} ;

int* SelectionSort::getElement( int* baseAddress , int index ) {
    int step = sizeof( int ) ;
    int* elementAddress = baseAddress + ( index * step ) ; 
    return elementAddress ; 
}

int* SelectionSort::sort( int* array , int size ) {
    for( int i = 0 ; i < size ;  i++ ) {
        int minElement = *getElement( array , i ) ;
        int minElementIndex = i ; 
        for( int j = i ; j < size ; j++ ) {
            if ( *getElement( array , j ) < minElement ){
                minElement = *getElement( array , j ) ;
                minElementIndex = j ; 
            }
        }
        if( minElementIndex != i ) {
        }
    }
}