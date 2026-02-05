/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 21:07:59 by msafa             #+#    #+#             */
/*   Updated: 2026/01/21 17:19:13 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
    :name(name) , weapon(NULL)
{}

void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}

Weapon& HumanB::getWeapon(void)
{
    return *this->weapon;
}

std::string HumanB::getName()
{
    return this->name;
}

void HumanB::attack(void)
{
    std::cout << HumanB::getName() 
              << " attacks with their " 
              << HumanB::getWeapon().getType()
              << std::endl;
}