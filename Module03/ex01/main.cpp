/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 16:19:31 by msafa             #+#    #+#             */
/*   Updated: 2026/01/31 18:52:21 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
    //default constructor test
    ScavTrap test1;
    std::cout << std::endl;
    
    //parameterized constructor test
    ScavTrap test2("safa");
    std::cout << std::endl;
    
    //copy constructor test
    ScavTrap test3(test2);
    std::cout << std::endl;
    
    // assignment operator test
    ScavTrap test4;
    test4 = test3;
    std::cout << std::endl;

    //scavTrap attack test
    test2.attack("evaluator");
    std::cout << std::endl;

    //scavTrap guardGate test
    test2.guardGate();
    std::cout << std::endl;
    
    //scavTrap takeDamage test (inherited from ClapTrap)
    test2.takeDamage(30);
    test2.takeDamage(50);
    std::cout << std::endl;
    
    //scavTrap beRepaired test (inherited from ClapTrap)
    test2.beRepaired(20);
    std::cout << std::endl;
    
    //scavTrap takeDamage to 0 HP
    test2.takeDamage(200);
    std::cout << std::endl;
    
    //scavTrap attack with 0 HP
    test2.attack("evaluator");
    test2.beRepaired(10);
    std::cout << std::endl;
    return 0;
}