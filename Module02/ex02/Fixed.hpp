/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:01:00 by msafa             #+#    #+#             */
/*   Updated: 2026/01/26 16:17:22 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int _value;
        static const int _fractional_bits = 8;
    public:
    //orthodox canonical form
        Fixed(void);
        Fixed(const Fixed& src);
        Fixed& operator=(const Fixed& rhs);
        ~Fixed();
    //constructors to create the fixed-point number
        Fixed(const int nb);
        Fixed(const float nb);
    //getter & setter
        int getRawBits(void) const;
        void setRawBits(int const raw);
    //conversion methods
        float toFloat(void) const;
        int toInt(void) const;
    //6 comparison operators
        bool operator>(const Fixed& rhs) const;
        bool operator<(const Fixed& rhs) const;
        bool operator>=(const Fixed& rhs) const;
        bool operator<=(const Fixed& rhs) const;
        bool operator==(const Fixed& rhs) const;
        bool operator!=(const Fixed& rhs) const;
    //4 arithmetic operators 
        Fixed operator+(const Fixed& rhs) const;
        Fixed operator-(const Fixed& rhs) const;
        Fixed operator*(const Fixed& rhs) const;
        Fixed operator/(const Fixed& rhs) const;
    //4 increment/decrement operators
        Fixed& operator++(void);
        Fixed operator++(int);
        Fixed& operator--(void);
        Fixed operator--(int);
    // overloaded functions
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a , const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed&a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif