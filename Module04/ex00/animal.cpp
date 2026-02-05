/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 20:23:15 by msafa             #+#    #+#             */
/*   Updated: 2026/02/01 22:49:00 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"

Animal::Animal()
    :type("default")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string& type)
{
    this->type = type;
    std::cout << "Animal parameterized constructor called" << std::endl;
}

Animal::Animal(const Animal& src)
{
    this->type = src.type;
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& rhs)
{
    if(this != &rhs)
        this->type = rhs.type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;   
}

void Animal::makeSound() const
{
    std::cout << "No sound!" << std::endl;
}

WrongAnimal::WrongAnimal()
    :type("default")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type)
{
    this->type = type;
    std::cout << "WrongAnimal parameterized constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
    this->type = src.type;
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
    if(this != &rhs)
        this->type = rhs.type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "Wrong sound!" << std::endl;
}
