/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 23:22:38 by msafa             #+#    #+#             */
/*   Updated: 2026/02/02 01:02:57 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain& src)
{
    for(int i = 0; i < 100; i++)
        this->ideas[i] = src.ideas[i];
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& rhs)
{
    if(this != &rhs)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = rhs.ideas[i];
    }
    return *this;
}

void Brain::setIdea(int index,std::string idea)
{
    if(index >=0 && index < 100)
        this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
    if(index >=0 && index < 100)
        return this->ideas[index];
    return "";
}