/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 21:08:04 by msafa             #+#    #+#             */
/*   Updated: 2026/01/23 23:49:46 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name,Weapon& weapon)
    :name(name) ,weapon(weapon)
{}

const std::string& HumanA::getName(void) const
{
    return this->name;
}

Weapon& HumanA::getWeapon(void)
{
    return weapon;
}
void HumanA::attack(void)
{
    std::cout << HumanA::getName()
              << " attacks with their "
              << HumanA::getWeapon().getType()
              << std::endl;
}