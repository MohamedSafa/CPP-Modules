/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:01:02 by msafa             #+#    #+#             */
/*   Updated: 2026/01/28 15:20:33 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    //subject main
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    
    // my main
    std::cout << std::endl;

    Fixed x(5);
    Fixed y(10);
    
    std::cout << (x > y) << std::endl;
    std::cout << (x < y) << std::endl;
    std::cout << (x >= y) << std::endl;
    std::cout << (x == y) << std::endl;
    std::cout << (x + y) << std::endl;
    std::cout << (y - x) << std::endl;
    std::cout << (x * y) << std::endl;
    std::cout << (y / x) << std::endl;
    std::cout << Fixed::min(x, y) << std::endl;
    std::cout << Fixed::max(x, y) << std::endl;
    
    Fixed f(42.42f);
    
    std::cout << f.toInt() << std::endl;
    std::cout << f.getRawBits() << std::endl;

    return 0;
}