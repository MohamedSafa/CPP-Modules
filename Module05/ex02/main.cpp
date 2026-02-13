/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 20:35:56 by msafa             #+#    #+#             */
/*   Updated: 2026/02/07 17:27:14 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    //test 1
    ShrubberyCreationForm one("one");
    RobotomyRequestForm two("two");
    PresidentialPardonForm three("three");
    // test2
    Bureaucrat safa("safa",1);
    safa.executeForm(one);
    // test3
    safa.signForm(two);
    safa.signForm(one);
    safa.signForm(three);
    safa.executeForm(two);
    safa.executeForm(one);
    safa.executeForm(three);
    //test 4
    Bureaucrat safa2("safa2",42);
    safa2.signForm(three);
    safa2.executeForm(three);
    //test 5
    Bureaucrat safa3("safa3" , 72);
    safa3.signForm(two);
    safa3.executeForm(two);
    return 0;
}
