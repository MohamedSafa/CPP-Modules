/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 20:33:57 by msafa             #+#    #+#             */
/*   Updated: 2026/02/01 23:33:17 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"dog.hpp"

Dog::Dog() : Animal("Dog")
{   
    this->brain = new Brain();
    std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src)
{   
    this->brain = new Brain(*src.brain);
     std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
    if(this != &rhs)
    {
        Animal::operator=(rhs);
        *this->brain = *rhs.brain;
    }
    return *this;
}

Dog::~Dog()
{   
    delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof woof!" << std::endl;
}

void Dog::setIdea(int index, std::string idea)
{
    this->brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
    return this->brain->getIdea(index);
}
