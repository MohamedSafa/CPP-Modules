/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 20:48:44 by msafa             #+#    #+#             */
/*   Updated: 2026/02/17 17:50:05 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int main(void)
{
    // vector container
    std::vector<int> container1;
    std::vector<int>::iterator occurrence1;
    container1.push_back(1);
    container1.push_back(3);
    container1.push_back(2);
    try
    {
        occurrence1 = easyfind(container1,3);
        std::cout << (occurrence1 - container1.begin()) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    // doubly linked list container
    std::list<int> container2;
    std::list<int>::iterator occurrence2;
    container2.push_back(10);
    container2.push_back(20);
    container2.push_front(30);
    try
    {
        occurrence2 = easyfind(container2,30);
        std::cout << *occurrence2 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    // deque container
    std::deque<int> container3;
    std::deque<int>::iterator occurrence3;
    container3.push_back(41);
    container3.push_back(42);
    container3.push_back(40);
    try
    {
        occurrence3 = easyfind(container3,42);
        std::cout << (occurrence3 - container3.begin()) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    // error 
    try
    {
        occurrence1 = easyfind(container1,4);
        std::cout << (occurrence1 - container1.begin()) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}