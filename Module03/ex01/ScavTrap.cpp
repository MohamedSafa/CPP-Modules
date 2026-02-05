/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 16:09:12 by msafa             #+#    #+#             */
/*   Updated: 2026/01/31 17:24:43 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
    std::cout << "ScavTrap " << this->Name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{
    std::cout << "ScavTrap " << this->Name << " copy constructor called" << std::endl;   
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
    if(this != &rhs)
    {
        ClapTrap::operator=(rhs);
        std::cout << "ScavTrap " << this->Name << " copy assignment operator called" << std::endl;
    }
    return *this;

}

void ScavTrap::attack(const std::string& target)
{
    if(this->HitPoints > 0 && this->EnergyPoints > 0)
    {
             std::cout << "ScavTrap "
                  << this->Name
                  << " attacks "
                  << target
                  << ", causing "
                  << this->AttackDamage
                  << " points of damage!"
                  << std::endl;
        this->EnergyPoints -= 1;
    }
    else
    {
         std::cout << "ScavTrap "
            << this->Name
            << " can't do anything!\n"
            << "Energy points: "
            << this->EnergyPoints
            << "\nHitPoints: "
            << this->HitPoints
            << std::endl;
    }
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->Name << " is now in Gate keeper mode" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap default destructor called" << std::endl;
}