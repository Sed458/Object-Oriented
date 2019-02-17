//
//  Rational.hpp
//  rec08
//
//  Created by Sophia Danielsen on 10/27/17.
//  Copyright © 2017 Sophia Danielsen. All rights reserved.
//

#ifndef Rational_hpp
#define Rational_hpp

#include <iostream>

namespace CS2124 {
    class Rational {
    public:
        Rational();
        
        Rational(int numerator);
        
        Rational (int _numerator, int _denominator);
        
        friend std::ostream& operator<<(std::ostream& os, Rational& rational);
        friend std::istream& operator>>(std::istream& is, Rational& rational);
        friend bool operator==(const Rational& lhs, const Rational& rhs);
        
        Rational& operator+=(const Rational& rhs);
        
        Rational& operator++();
        
        Rational operator++(int);
        
        explicit operator bool() const;
        
        //Reduce Fraction
        void normalize();
        
    private:
        int numerator;
        int denominator;
    };
    
    Rational operator+(const Rational& lhs, const Rational& rhs);
    
    bool operator!=(Rational& lhs, Rational& rhs);
    
    Rational& operator--(Rational& rhs);
    
    Rational operator--(Rational& rhs, int);
}

#endif /* Rational_hpp */
