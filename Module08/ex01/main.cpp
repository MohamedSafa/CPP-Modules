/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:51:35 by msafa             #+#    #+#             */
/*   Updated: 2026/02/18 21:20:23 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <algorithm>

int main()
{
    // subejct test
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    // empty span
    Span test;
    try
    {
        std::cout << test.shortestSpan() << std::endl;
        std::cout << test.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    // single integer
    Span test1 = Span(1);
    test1.addNumber(42);
    try
    {
        std::cout << test1.shortestSpan() << std::endl;
        std::cout << test1.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    //overfilling
    Span test2(3);
    for(int i = 1; i < 5 ; i++ )
    {
        try
        {
            test2.addNumber(i);
            std::cout << "Filled" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    // huge number
    std::vector<int>container;
    for(int i = 1; i < 42000 ; i++)
        container.push_back(i);
    Span test3(42000);
    std::random_shuffle(container.begin(),container.end());
    test3.addRange(container.begin(),container.end());
    std::cout << test3.shortestSpan() << std::endl;
    std::cout << test3.longestSpan() << std::endl;
    return 0;
}