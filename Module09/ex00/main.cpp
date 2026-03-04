/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 23:50:34 by msafa             #+#    #+#             */
/*   Updated: 2026/02/21 01:58:51 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc,char *argv[])
{
    if(argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1 ;
    }
    BitcoinExchange test;
    test.loadDatabase("data.csv");
    test.processInput(argv[1]);
    return 0;
}