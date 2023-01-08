#include <iostream>
#include "stack_array.h"

class ValidParenthesisChecker {

private:

    static bool matchParenthesis( char c1 , char c2 ) {
        return abs( int(c1) - int(c2) ) <= 2 ;
    }

public:

    static bool check( const std::string& expression ) {
        StackArray<char> stack((int) expression.length() ) ;
        for( char c : expression ) {
            if( c == '(' || c == '[' || c == '{' ) {
                stack.push( c ) ;
            }
            else if( c == ')' || c == ']' || c == '}' ) {
                if( matchParenthesis( c , stack.head() ) ) {
                    stack.pop() ;
                }
                else {
                    return false ;
                }
            }
        }
        return stack.isEmpty() ;
    }

};


