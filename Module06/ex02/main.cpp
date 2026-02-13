/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:57:37 by msafa             #+#    #+#             */
/*   Updated: 2026/02/13 16:30:57 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

int main(void)
{
    Base* test = generate();
    std::cout << "Type of the object pointed to: ";
    identify(test);
    std::cout << "Type of the object referenced by: ";
    identify(*test);
    delete test;
    return 0;
}