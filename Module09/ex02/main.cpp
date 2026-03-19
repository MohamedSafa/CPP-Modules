/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 20:42:16 by msafa             #+#    #+#             */
/*   Updated: 2026/03/16 21:33:09 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int main(int argc,char *argv[])
{
    PmergeMe test;
    try
    {
        clock_t start = clock();
        test.parse_and_validate(argc,argv);
        test.display_arr("Before:");
        test.sort();
        test.display_arr("After:");
        double vecTime = (double)(test.getVecEnd() - start) / CLOCKS_PER_SEC * 1e6;
        double deqTime = (double)(test.getDeqEnd() - start) / CLOCKS_PER_SEC * 1e6;
        std::cout << std::fixed << std::setprecision(5);
        std::cout << "Time to process a range of " << test.size() << " elements with std::vector : " << vecTime << " us" << std::endl;
        std::cout << "Time to process a range of " << test.size() << " elements with std::deque  : " << deqTime << " us" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}