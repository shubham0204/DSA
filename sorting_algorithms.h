#ifndef DSA_SORTING_ALGORITHMS_H
#define DSA_SORTING_ALGORITHMS_H
#include <cmath>

/*
This class contains various sorting algorithms that operate on generic data types
The following algorithms are implemented:
1. Bubble Sort ( Sinking Sort )
2. Selection Sort
3. Insertion Sort
4. Shell Sort
5. Quick Sort
6. Counting Sort
7. Radix Sort

 Each method like `selectionSort` has two parameters,
 - `array` of type `E*` that points to the first element of the array to be sorted.
 - `size` of type `int` representing the size of the array
*/
template <class E>
class SortingAlgorithms {

public:

    static void bubbleSort( E* array , int size ) ;
    static void selectionSort( E* array , int size ) ;
    static void insertionSort( E* array , int size ) ;
    static void shellSort( E* array , int size ) ;
    static void quickSort( E* array , int size ) ;

    static int* countingSort( const int* array , int size ) ;
    static void radixSort( E* array , int size ) ;

    static void heapSort( E* array , int size ) ;
    static void mergeSort( E* array , int size ) ;
    static void timmSort( E* array , int size ) ;


private:
    static void quickSortRecursive( E* array , int lower , int upper ) ;
    static int quickSortPartition( E* array , int lower , int upper ) ;

} ;

/*
 * Implement the bubble sort algorithm
 * The algorithm performs swaps of adjacent elements until the largest element is "bubbled" or "shifted"
 * to the rightmost position in each pass.
 *
 * Properties:
 * - comparison-based
 * - in-place
 * - stable
 * - for internal sorting only.
 *
 * Time and Space Complexity:
 * - Worst and average-case time complexity: O( N^2 ) comparisons, O( N^2 ) swaps
 * - Best case time complexity: O( N ) comparisons, O( 1 ) swaps
 * - Space Complexity: O( 1 ) always
 */
template<class E>
void SortingAlgorithms<E>::bubbleSort(E *array, int size) {
    for( int i = 0 ; i < size ; i++ ) {
        for( int j = 0 ; j < ( size - 1 ) - i ; j++ ) {
            bool swapped = false ;
            if( *( array + j ) > *( array + j + 1 ) ) {
                E temp = *( array + j ) ;
                *( array + j ) = *( array + j + 1 ) ;
                *( array + j + 1 ) = temp ;
                swapped = true ;
            }
            if( !swapped ) {
                break;
            }
        }
    }
}


/*
 * Implement the selection sort algorithm
 * In each kth pass, we determine the k-smallest element and place it at the (k - 1)th index
 *
 * Properties:
 * - comparison-based
 * - in-place
 * - stable
 * - for internal sorting only.
 *
 * Time and Space Complexity:
 * - Worst and average-case time complexity: O( N^2 ) comparisons, O( N ) swaps
 * - Best case time complexity: O( N^2 ) comparisons, O( 1 ) swaps
 * - Space Complexity: O( 1 ) always
 */
template <class E>
void SortingAlgorithms<E>::selectionSort( E* array, int size) {
    for( int i = 0 ; i < size ; i++ ) {
        E* minElement = array + i ;
        for( int j = i ; j < size ; j++ ) {
            if( *( array + j ) < *minElement ) {
                minElement = array + j ;
            }
        }
        if( *minElement != *( array + i ) ) {
            E temp = *minElement ;
            *minElement = *( array + i ) ;
            *( array + i ) = temp ;
        }
    }
}


/*
 * Implement the insertion sort algorithm
 * We iterate through element ( say the kth element ) and place it in its correct position in the array,
 * that is already swept ( i.e. the subarray from [0 , k - 1] ). It is most efficient than selection sort
 * and bubble sort for arrays that are nearly sorted.
 *
 * Properties:
 * - comparison-based
 * - in-place
 * - stable
 * - online: It can sort array elements as it receives newer elements.
 *
 * Time and Space Complexity:
 * - Worst and average-case time complexity: O( N^2 ) comparisons and swaps
 * - Best case time complexity: O( N ) comparisons, O( 1 ) swaps
 * - Space Complexity: O( 1 ) always
 */
template <class E>
void SortingAlgorithms<E>::insertionSort( E* array , int size ){
    for( int k = 0 ; k < size ; k++ ) {
        for( int j = k ; j > 0 ; j-- ) {
            if( *( array + j ) < *( array + j - 1 ) ) {
                E temp = *( array + j ) ;
                *( array + j ) = *( array + j - 1 ) ;
                *( array + j - 1 ) = temp ;
            }
        }
    }
}


/*
 * Implement the shell sort algorithm
 * TODO: Edit description for shell sort
 * In each kth iteration, we determine the k-largest element and place it at the (n - k)th index
 *
 * Properties:
 * - comparison-based
 * - in-place
 * - stable
 * - for internal sorting only.
 *
 * Time and Space Complexity:
 * - Worst and average-case time complexity: O( N^2 )
 * - Best case time complexity: O( N )
 * - Space Complexity: O( 1 ) always
 */
template <class E>
void SortingAlgorithms<E>::shellSort( E* array , int size ){
    int gap = std::floor( float(size) / 2.0f ) ;
    while( gap >= 1 ) {
        for( int i = gap ; i < size ; i++ ) {
            for( int j = i ; j > ( gap - 1 ) ; j -= gap ) {
                if( *( array + j ) < *( array + j - gap ) ) {
                    E temp = *( array + j ) ;
                    *( array + j ) = *( array + j - gap ) ;
                    *( array + j - gap ) = temp ;
                }
            }
        }
        gap = std::floor( float(gap) / 2.0f ) ;
    }
}

/*
 * Implement the quick sort algorithm
 * TODO: Edit description for quick sort
 * In each kth iteration, we determine the k-largest element and place it at the (n - k)th index
 *
 * Properties:
 * - comparison-based
 * - in-place
 * - stable
 * - for internal sorting only.
 *
 * Time and Space Complexity:
 * - Worst and average-case time complexity: O( N^2 )
 * - Best case time complexity: O( N )
 * - Space Complexity: O( 1 ) always
 */
template <class E>
void SortingAlgorithms<E>::quickSort( E* array , int size ) {
    quickSortRecursive( array , 0 , size - 1 ) ;
}
template <class E>
void SortingAlgorithms<E>::quickSortRecursive( E* array , int lower , int upper ) {
    if( lower < upper && lower >= 0 && upper >= 0 ) {
        int partition = SortingAlgorithms<E>::quickSortPartition( array , lower , upper ) ;
        quickSortRecursive( array , lower , partition ) ;
        quickSortRecursive( array , partition + 1 , upper ) ;
    }
}
template <class E>
int SortingAlgorithms<E>::quickSortPartition( E *array, int lower , int upper ){
    int pivotIndex = std::floor( ( lower + upper ) / 2 ) ;
    E pivot = *( array + pivotIndex ) ;
    int i = lower - 1 ;
    int j = upper + 1 ;
    while( true ) {
        do { i++ ; }
        while( *( array + i ) < pivot ) ;
        do { j-- ; }
        while( *( array + j ) > pivot ) ;
        if( i >= j ) {
            return j ;
        }
        E temp = *( array + i ) ;
        *( array + i ) = *( array + j ) ;
        *( array + j ) = temp ;
    }
}


/*
 * Implement the Counting Sort algorithm
 * TODO: Edit description for counting sort
 * In each kth iteration, we determine the k-largest element and place it at the (n - k)th index
 *
 * Properties:
 * - non comparison-based
 * - in-place
 * - stable
 * - for internal sorting only.
 *
 * Time and Space Complexity:
 * - Worst and average-case time complexity: O( N^2 )
 * - Best case time complexity: O( N )
 * - Space Complexity: O( 1 ) always
 */
template <class E>
int* SortingAlgorithms<E>::countingSort( const int* array , int size ) {
    int maxElement = 0 ;
    for( int i = 0 ; i < size ; i++ ) {
        if( *( array + i ) > maxElement ) {
            maxElement = *( array + i ) ;
        }
    }

    int frequencies[ maxElement + 1 ] ;
    for( int i = 0 ; i < size ; i++ ) {
        frequencies[ *( array + i ) ]++ ;
    }

    int cumFrequencies[ maxElement + 1 ] ;
    cumFrequencies[ 0 ] = frequencies[ 0 ] ;
    for( int i = 1 ; i < maxElement + 1 ; i++ ) {
        cumFrequencies[ i ] = frequencies[ i ] + cumFrequencies[ i - 1 ] ;
    }

    int output[ size ] ;
    for( int i = size - 1 ; i > -1 ; i-- ) {
        int element = *( array + i ) ;
        cumFrequencies[ element ]-- ;
        output[ cumFrequencies[element] ] = element ;
    }

    return &output[0] ;
}

#endif //DSA_SORTING_ALGORITHMS_H
