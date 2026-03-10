/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 20:42:16 by msafa             #+#    #+#             */
/*   Updated: 2026/03/05 02:42:59 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int main(int argc,char *argv[])
{
    PmergeMe test;
    try
    {
        test.parse_and_validate(argc,argv);
        test.display_arr("Before:");
        test.sort();
        test.display_arr("After:");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}