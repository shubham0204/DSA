#ifndef DSA_SEARCHING_ALGORITHMS_H
#define DSA_SEARCHING_ALGORITHMS_H

/*
 *
 */
template <class E>
class SearchingAlgorithms {

public:

    static void linearSearch( E* array , int size , E key ) ;
    static void sentinelSearch( E* array , int size , E key ) ;
    static void binarySearch( E* array , int size , E key ) ;
    static void fibonacciSearch( E* array , int size , E key ) ;

};

#endif //DSA_SEARCHING_ALGORITHMS_H
