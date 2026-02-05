/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 17:36:20 by msafa             #+#    #+#             */
/*   Updated: 2026/01/31 18:46:27 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    this->HitPoints = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& Name) : ClapTrap(Name)
{
    this->HitPoints = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
    std::cout << "FragTrap " << this->Name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src)
{
    std::cout << "FragTrap " << this->Name << " copy constructor called" << std::endl;   
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
    if(this != &rhs)
    {
        ClapTrap::operator=(rhs);
        std::cout << "FragTrap " << this->Name << " copy assignment operator called" << std::endl;
    }
    return *this;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->Name << " requests a positive high-five!" << std::endl;

}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap default destructor called" << std::endl;
}
