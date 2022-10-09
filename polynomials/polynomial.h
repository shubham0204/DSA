#ifndef DSA_POLYNOMIAL_H
#define DSA_POLYNOMIAL_H

class Polynomial {

private:
    int degree ;
    struct Term {
        int exponent ;
        float coefficient ;
    };
    Term* termsBaseAddress ;

public:

    Polynomial( int polynomialDegree ) ;
    ~Polynomial() ;

    void setCoefficient( float coefficient , int exponent ) ;
    float getCoefficient( int exponent ) ;
    Polynomial add( Polynomial other ) ;

};

#endif //DSA_POLYNOMIAL_H
