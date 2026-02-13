/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 20:37:15 by msafa             #+#    #+#             */
/*   Updated: 2026/02/07 00:29:16 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    :AForm("ShrubberyCreationForm",145,137),_target("default")
{
    std::cout << "Shrubbery " << this->_target << " default constructor called" << std::endl; 
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Shrubbery " << this->_target << "destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
    :AForm(src) , _target(src._target)
{
    std::cout << "Shrubbery " << this->_target << "copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
    if(this != &rhs)
        AForm::operator=(rhs);
    std::cout << "Shrubbery " << this->_target << " assignment operator called" << std::endl;
    return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    :AForm("ShrubberyCreationForm",145,137) , _target(target)
{
    std::cout << "ShrubberyCreationForm " << this->_target << " parameterized constructor called" << std::endl;
}

void ShrubberyCreationForm::executeAction() const
{
    std::ofstream file((this->_target + "_shrubbery").c_str());
    if(!file.is_open())
        throw std::runtime_error("Could not open file");
    file << "       /\\       " << std::endl;
    file << "      /  \\      " << std::endl;
    file << "     /    \\     " << std::endl;
    file << "    /______\\    " << std::endl;
    file << "      ||||      " << std::endl;
    file.close();
}