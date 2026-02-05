/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 16:58:44 by msafa             #+#    #+#             */
/*   Updated: 2026/01/30 21:06:13 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    //Constructor call
    ClapTrap a("Alpha");
    ClapTrap b("Beta");
    std::cout << std::endl;
    // copy constructor call
    ClapTrap c(a);
    std::cout << std::endl;
    // copy assignment operator call
    b = a;
    std::cout << std::endl;
    //attack test
    a.attack("target");
    std::cout << std::endl;
    //take damage test
    a.takeDamage(3);
    a.takeDamage(5);
    std::cout << std::endl;
    //repair test
    a.beRepaired(4);
    std::cout << std::endl;
    // hitPoints set to zero to avoid negative values
    a.takeDamage(20);
    std::cout << std::endl;
    //attack with zero HP
    a.attack("target");
    a.beRepaired(5);
    std::cout << std::endl;
    // drain all energy points
    ClapTrap d("Delta");
    for (int i = 0; i < 11; i++)
        d.attack("enemy");
    std::cout << std::endl;
    // repair with zero EP
    d.beRepaired(3);
    std::cout << std::endl;
    return(0);
}
