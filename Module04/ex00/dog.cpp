/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 20:33:57 by msafa             #+#    #+#             */
/*   Updated: 2026/01/31 23:26:40 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src)
{
     std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
    if(this != &rhs)
        Animal::operator=(rhs);
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof woof!" << std::endl;     
}
