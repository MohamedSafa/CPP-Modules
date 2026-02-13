/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 20:38:02 by msafa             #+#    #+#             */
/*   Updated: 2026/02/07 00:37:40 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
    :AForm("RobotomyRequestForm",72,45),_target("default")
{
    std::cout << "RobotomyRequestForm " << this->_target << " default constructor called" << std::endl; 
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm " << this->_target << " destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
    :AForm(src) , _target(src._target)
{
    std::cout << "RobotomyRequest " << this->_target << " copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
    if(this != &rhs)
        AForm::operator=(rhs);
    std::cout << "RobotomyRequestForm " << this->_target << " assignment operator called" << std::endl;
    return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    :AForm("RobotomyRequestForm",72,45) , _target(target)
{
    std::cout << "RobotomyRequestForm " << this->_target << " parameterized constructor called" << std::endl;
}

void RobotomyRequestForm::executeAction() const
{
    std::srand(std::time(NULL));
    std::cout << "zzzzzzz..grgrgrgrg\n";
    if(std::rand() % 2)
        std::cout << this->_target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << this->_target << " robotomy failed." << std::endl;
}
