#include <iostream>
#include <cmath>
#include "polynomial.h"

Polynomial::Polynomial(int polynomialDegree) {
    degree = polynomialDegree ;
    termsBaseAddress = new Term[ degree ] ;
}

Polynomial::~Polynomial() {
    delete termsBaseAddress ;
}

void Polynomial::setCoefficient(float coefficient, int exponent) {
    Term* updateTerm = termsBaseAddress + exponent ;
    updateTerm -> coefficient = coefficient ;
}

float Polynomial::getCoefficient(int exponent) {
    Term* updateTerm = termsBaseAddress + exponent ;
    return updateTerm -> coefficient ;
}

Polynomial Polynomial::add(Polynomial other) {
    int resPolyDegree = std::max( degree , other.degree ) ;
    int i = 0 ;
    Term* resPolyTerms = new Term[ resPolyDegree ] ;
    while( i < std::min( degree , other.degree ) ) {
        resPolyTerms -> coefficient = getCoefficient( i ) + other.getCoefficient( i ) ;
        resPolyTerms++ ;
        i++ ;
    }
}



