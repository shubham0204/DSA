#include <iostream>
using namespace std ;

class SparseMatrixArray {

private:
    int numNonZeroElements ;
    int numRows ;
    int numColumns ;
    float** data ;

public:

    SparseMatrixArray( int numRows , int numColumns , int numNonZeroElements ) ;

    friend SparseMatrixArray operator+( const SparseMatrixArray& A , const SparseMatrixArray& B ) {
        int ap = 0 ;
        int bp = 0 ;
        int resp = 0 ;
        while( ap < A.numNonZeroElements && bp < B.numNonZeroElements ) {
            if( ( A.data[ap][0] > B.data[bp][0] ) ||
                    ( (A.data[ap][0] == B.data[bp][0]) && A.data[ap][1] > B.data[bp][1] ) ) {

            }
        }
    }

};

SparseMatrixArray::SparseMatrixArray(int numRows, int numColumns, int numNonZeroElements) {
    this -> numRows = numRows ;
    this -> numColumns = numColumns ;
    this -> numNonZeroElements = numNonZeroElements ;
}
