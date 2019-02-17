//
//  Rational.cpp
//  rec08
//
//  Created by Sophia Danielsen on 10/27/17.
//  Copyright © 2017 Sophia Danielsen. All rights reserved.
//

#include "Rational.hpp"

#include <iostream>
using namespace std;

namespace CS2124 {
    Rational::Rational() : Rational(0,1) {}
    
    Rational::Rational(int numerator) : Rational(numerator,1) {}
    
    Rational::Rational(int _numerator, int _denominator) : numerator(_numerator), denominator(_denominator) {}
    
    Rational& Rational::operator+=(const Rational& rhs) {
        numerator = ((rhs.denominator * numerator) + (denominator * rhs.numerator));
        denominator *= rhs.denominator;
        normalize();
        return *this;
    }
    
    Rational& Rational::operator++() {
        numerator += denominator;
        normalize();
        return *this;
    }
    
    Rational Rational::operator++(int){
        Rational original(*this);
        numerator += denominator;
        normalize();
        return original;
    }
    
     Rational::operator bool() const {
        return !(numerator == 0);
    }
    
    int greatestCommonDivisor(int numerator, int denominator) {
        while (denominator != 0) {
            int temp = numerator % denominator;
            numerator = denominator;
            denominator = temp;
        }
        return numerator;
    }
    
    void Rational::normalize() {
        int divideBy = greatestCommonDivisor(numerator, denominator);
        numerator /= divideBy;
        denominator /= divideBy;
        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
    }
    
    
    istream& operator>>(istream& is, Rational& rhs){
        int numerator;
        int denominator;
        char slash;
        
        cin >> numerator >> slash >> denominator;
        
        int divideBy = greatestCommonDivisor(numerator, denominator);
        numerator /= divideBy;
        denominator /= divideBy;
        
        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
        
        rhs.numerator = numerator;
        rhs.denominator = denominator;
        
        return is;
    }
    
    ostream& operator<<(ostream& os, Rational& rhs){
        os << rhs.numerator << '/' << rhs.denominator;
        return os;
    }
    
    Rational operator+(const Rational& lhs, const Rational& rhs){
        Rational result(lhs);
        result += rhs;
        return result;
    }
    
    bool operator==(const Rational& lhs, const Rational& rhs) {
        return (lhs.numerator == rhs.numerator && lhs.denominator == rhs.denominator);
    }
    
    bool operator!=(Rational& lhs, Rational& rhs) {
        return !(lhs == rhs);
    }
    
    Rational& operator--(Rational& rhs) {
        return (rhs += -1);
    }
    
    Rational operator--(Rational& rhs, int) {
        Rational original(rhs);
        rhs += -1;
        return original;
    }
}
