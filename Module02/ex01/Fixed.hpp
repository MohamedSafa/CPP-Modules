/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:51:38 by msafa             #+#    #+#             */
/*   Updated: 2026/01/25 20:18:25 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    private:
        int _value;
        static const int _fractionalBits = 8;
    public:
        Fixed(void);
        Fixed(const Fixed& src);
        Fixed& operator=(const Fixed &rhs);
        Fixed(const int nb);
        Fixed(const float nb);
        ~Fixed();
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out,const Fixed& fixed);

#endif