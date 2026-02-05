/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 17:37:57 by msafa             #+#    #+#             */
/*   Updated: 2026/01/31 18:52:04 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    //FragTrap default constructor test
    FragTrap test1;
    std::cout << std::endl;

    //FragTrap parameterized constructor test
    FragTrap test2("safa");
    std::cout << std::endl;

    //FragTrap copy constructor test
    FragTrap test3(test2);
    std::cout << std::endl;
    
    //FragTrap assignment operator test
    FragTrap test4;
    test4 = test3;
    std::cout << std::endl;

    //FragTrap attack test (inherited from ClapTrap)
    test2.attack("evaluator");
    std::cout << std::endl;
    
    //FragTrap highFivesGuys test
    test2.highFivesGuys();
    std::cout << std::endl;
    
    //FragTrap takeDamage test (inherited from ClapTrap)
    test2.takeDamage(30);
    test2.takeDamage(50);
    std::cout << std::endl;
    
    //FragTrap beRepaired test (inherited from ClapTrap)
    test2.beRepaired(20);
    std::cout << std::endl;

    //FragTrap takeDamage to 0 HP
    test2.takeDamage(200);
    std::cout << std::endl;
    
    //FragTrap attack with 0 HP
    test2.attack("evaluator");
    test2.beRepaired(10);
    std::cout << std::endl;
    return 0;
}