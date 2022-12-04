#include "stack_array.cpp"
#include <iostream>

class InfixConverter {

private:

    char operations[ 7 ] = { '+' , '-' , '/' , '*' , '^' , '(' , ')' } ;
    int precedences[ 7 ] = { 0 , 0 , 1 , 1 , 2 , 3 , 3 };

    int getPrecedence( char operation ) {
        int i = 0 ;
        for( char c : operations ) {
            if( c == operation ) {
                return precedences[ i ] ;
            }
            i++ ;
        }
        return -1 ;
    }

public:

    std::string convertToPostFix( std::string infixExpression ) {
        Stack<char> stack( infixExpression.length() ) ;
        std::string postfixExpression = "" ;
        for( char c : infixExpression ) {
            if( getPrecedence( c ) == -1 ) {
                // Character `c` is not an operator or parenthesis
                // Append operand to the postfix expression
                postfixExpression += c ;
            }
            else {
                // Character `c` could be an operator or parenthesis
                if(getPrecedence( c ) < 3) {
                    // Character `c` is an operator
                    if( stack.head() == '(' || stack.isEmpty() ) {
                        stack.push( c ) ;
                    }
                    else if( getPrecedence( c ) > getPrecedence( stack.head() ) ) {
                        stack.push( c ) ;
                    }
                    else if( getPrecedence( c ) < getPrecedence( stack.head() ) ) {
                        postfixExpression += stack.pop() ;
                        continue;
                    }
                    else if( getPrecedence( c ) == getPrecedence( stack.head() ) ) {
                        postfixExpression += stack.pop() ;
                        continue;
                    }
                }
                else {
                    // Character `c` is `(` or `)`
                    if( c == '(' ) {
                        stack.push( c ) ;
                    }
                    else if( c == ')' ) {
                        while( stack.pop() != '(' ){
                            postfixExpression += stack.pop() ;
                        }
                    }
                }
            };
            stack.print() ;
        }
        while( stack.getNumElements() != 0 ){
            postfixExpression += stack.pop() ;
        }
        return postfixExpression ;
    }




};
