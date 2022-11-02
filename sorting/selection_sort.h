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
