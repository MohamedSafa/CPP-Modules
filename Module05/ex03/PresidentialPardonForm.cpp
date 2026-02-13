/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 20:38:23 by msafa             #+#    #+#             */
/*   Updated: 2026/02/07 00:50:29 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    :AForm("PresidentialPardonForm",25,5) , _target("default")
{
    std::cout << "PresidentialPardonForm " << this->_target << " default constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm " << this->_target << " destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
    :AForm(src) , _target(src._target)
{
    std::cout << "PresidentialPardonForm " << this->_target << " copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
    if(this != &rhs)
        AForm::operator=(rhs);
    std::cout << "PresidentialPardonForm " << this->_target << " assignment operator called" << std::endl;
    return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    :AForm("PresidentialPardonForm",25,5) , _target(target)
{
    std::cout << "PresidentialPardonForm " << this->_target << " parameterized constructor called" << std::endl;
}

void PresidentialPardonForm::executeAction() const
{
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}