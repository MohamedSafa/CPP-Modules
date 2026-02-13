/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:38:43 by msafa             #+#    #+#             */
/*   Updated: 2026/02/07 19:57:28 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
    std::cout << "Intern default constructor called\n";
}

Intern::~Intern()
{
    std::cout << "Intern destructor called\n";
}

Intern::Intern(const Intern& src)
{
    (void)src;
    std::cout << "Intern copy constructor called\n";
}

Intern& Intern::operator=(const Intern& rhs)
{
    (void)rhs;
    std::cout << "Intern assignment operator called\n";
    return *this;
}

AForm* Intern::createShrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& form,const std::string& target)
{
    Functs functs[3] = {
        {"shrubbery creation",createShrubbery},
        {"robotomy request",createRobotomy},
        {"presidential pardon",createPresidential}
    };
    for(int i = 0; i < 3; i++)
    {
        if(form == functs[i].name)
        {
            std::cout << "Intern creates " << form << std::endl;
            return functs[i].create(target);
        }
    }
    std::cout << "Intern couldn't create " << form << ": form not found" << std::endl;
    return NULL;
}

