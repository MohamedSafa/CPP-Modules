/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 23:02:37 by msafa             #+#    #+#             */
/*   Updated: 2026/02/23 00:11:43 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char*argv[])
{
    if(argc != 2)
    {
        std::cerr << "Error: not enough arguments" << std::endl;
        return 1;
    }
    RPN test;
    test.calculate(argv[1]);
    return 0;
}