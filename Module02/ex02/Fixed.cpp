/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:00:58 by msafa             #+#    #+#             */
/*   Updated: 2026/01/28 14:50:58 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//orthodox canonical form
Fixed::Fixed(void)
    :_value(0)
{}

Fixed::Fixed(const Fixed& src)
{
    *this = src;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
    if(this != &rhs)
        this->_value = rhs._value;
    return *this;
}

Fixed::~Fixed(void)
{
}

//constructors to create the fixed-point number
Fixed::Fixed(const int nb)
    :_value(nb << _fractional_bits)
{}

Fixed::Fixed(const float nb)
    :_value(roundf(nb * (1 << _fractional_bits)))
{}

//getter & setter
int Fixed::getRawBits(void) const
{
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

//conversion methods
float Fixed::toFloat(void) const
{
    return static_cast<float>(this->_value) / (1 << _fractional_bits);
}

int Fixed::toInt(void) const
{
    return this->_value >> _fractional_bits;
}

//6 comparison operators
bool Fixed::operator>(const Fixed& rhs) const
{
    return this->_value > rhs._value;
}

bool Fixed::operator<(const Fixed& rhs) const
{
    return this->_value < rhs._value;
}

bool Fixed::operator>=(const Fixed& rhs) const
{
    return this->_value >= rhs._value;
}

bool Fixed::operator<=(const Fixed& rhs) const
{
    return this->_value <= rhs._value;
}

bool Fixed::operator==(const Fixed& rhs) const
{
    return this->_value == rhs._value;
}

bool Fixed::operator!=(const Fixed& rhs) const
{
    return this->_value != rhs._value;
}

//4 arithmetic operators
Fixed Fixed::operator+(const Fixed& rhs) const
{
    Fixed result;
    result._value = this->_value + rhs._value;
    return result;
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
    Fixed result;
    result._value = this->_value - rhs._value;
    return result;
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
    Fixed result;
    result._value = (this->_value * rhs._value) >> _fractional_bits;
    return result;
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
    Fixed result;
    result._value = (this->_value << _fractional_bits) / rhs._value;
    return result;
}

//4 increment/decrement operators
Fixed& Fixed::operator++(void)
{
    this->_value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->_value++;
    return temp;
}

Fixed& Fixed::operator--(void)
{
    this->_value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->_value--;
    return temp;
}

//overloaded static functions
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if(a < b)
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if(a < b)
        return a;
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if(a > b)
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if(a > b)
        return a;
    return b;
}

//stream operator
std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}
