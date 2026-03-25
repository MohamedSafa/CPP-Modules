/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 23:50:34 by msafa             #+#    #+#             */
/*   Updated: 2026/03/22 22:18:12 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc,char *argv[])
{
    if(argc != 2)
    {
        std::cerr << "Error: No args" << std::endl;
        return 1 ;
    }
    try
    {
        BitcoinExchange test;
        test.loadDatabase("data.csv");
        test.processInput(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}