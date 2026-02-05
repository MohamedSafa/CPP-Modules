/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 16:58:39 by msafa             #+#    #+#             */
/*   Updated: 2026/01/30 21:05:26 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
     :Name("Default"), HitPoints(10) , EnergyPoints(10) , AttackDamage(0)
{
    std::cout << "ClapTrap " << this->Name << " default constructor has been called" << std::endl;
}

ClapTrap::ClapTrap(std::string Name)
    :Name(Name) , HitPoints(10) , EnergyPoints(10) , AttackDamage(0)
{
    std::cout << "ClapTrap " << this->Name << " constructor has been called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
    this->Name = src.Name;
    this->HitPoints = src.HitPoints;
    this->EnergyPoints = src.EnergyPoints;
    this->AttackDamage = src.AttackDamage;
    std::cout << "ClapTrap " << this->Name << " copy constructor has been called" << std::endl;
}

ClapTrap& ClapTrap:: operator=(const ClapTrap& rhs)
{
    if(this != &rhs)
    {
        std::cout << "ClapTrap " << rhs.Name << " copy assignment operator has been called" << std::endl;
        this->Name = rhs.Name;
        this->HitPoints = rhs.HitPoints;
        this->EnergyPoints = rhs.EnergyPoints;
        this->AttackDamage = rhs.AttackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->Name << " destructor has been called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if(this->HitPoints > 0 && this->EnergyPoints > 0)
    {
        std::cout << "ClapTrap "
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
        std::cout << "ClapTrap "
            << this->Name
            << " can't do anything!\n"
            << "Energy points: "
            << this->EnergyPoints
            << "\nHitPoints: "
            << this->HitPoints
            << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if(amount >= this->HitPoints)
    {
        this->HitPoints = 0;
         std::cout << "ClapTrap "
              << this->Name
              << " has no HitPoints left"
              << std::endl;
    }
    else
    {
        this->HitPoints -= amount;
        std::cout << "ClapTrap "
              << this->Name
              << " loses "
              << amount
              << " hitPoints"
              << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(this->HitPoints >0 && this->EnergyPoints > 0)
    {
         std::cout << "ClapTrap "
              << this->Name
              << " regains "
              << amount
              << " hitPoints"
              << std::endl;
        this->EnergyPoints -= 1;
        this->HitPoints += amount;
    }
    else
    {
         std::cout << "ClapTrap " << this->Name << " can't do anything!" << std::endl;
    }
    
    
}