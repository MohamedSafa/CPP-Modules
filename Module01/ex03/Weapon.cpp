/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 21:07:06 by msafa             #+#    #+#             */
/*   Updated: 2026/01/21 15:59:21 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
    :type(type)
{}

const std::string& Weapon::getType (void)
{
    return this->type;
}

void Weapon::setType(std::string new_value)
{
    this->type = new_value;
}