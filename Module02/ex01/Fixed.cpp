/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:51:42 by msafa             #+#    #+#             */
/*   Updated: 2026/01/28 15:23:54 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
    :_value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src ;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &rhs)
        this->_value = rhs._value;
    return *this;
}

Fixed::Fixed(const int nb)
{
    std::cout << "Int constructor called" << std::endl;
    this->_value = nb * (1 << this->_fractionalBits);
}

Fixed::Fixed(const float nb)
{
    std::cout << "Float constructor called" << std::endl;
   this->_value = static_cast<int>(roundf(nb * ( 1 << this->_fractionalBits)));
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}  

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(this->_value) / (1 << this->_fractionalBits);
}

int Fixed::toInt(void) const
{
    return this->_value / (1 << this->_fractionalBits);
}

std::ostream& operator<<(std::ostream& out,const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}
