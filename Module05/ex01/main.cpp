/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 00:11:54 by msafa             #+#    #+#             */
/*   Updated: 2026/02/05 23:20:02 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    // test1
    Form f1("f1",42,42);
    std::cout << f1 << std::endl;
    // test2
    Bureaucrat b1("b1",7);
    try
    {
        b1.signForm(f1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    //test3
    Bureaucrat b2("b2",50);
    Form f2(f1);
    try
    {
        b2.signForm(f2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    //test 4
    try
    {
       Form f3("f3",151,151);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}