/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:02:26 by msafa             #+#    #+#             */
/*   Updated: 2026/01/25 19:20:45 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
    private:
        int _value;
        static const int _fractionalBits = 8;
    public:
        Fixed(void);
        Fixed(const Fixed& src);
        Fixed& operator=(const Fixed &rhs);
        ~Fixed();
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};

#endif