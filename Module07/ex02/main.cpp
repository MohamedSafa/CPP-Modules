/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 20:31:37 by msafa             #+#    #+#             */
/*   Updated: 2026/02/15 01:50:19 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main(void)
{
    std::cout << "===== Default Constructor =====" << std::endl;
    Array<int> test1;
    std::cout << "test1 size: " << test1.size() << std::endl;
    try
    {
        std::cout << test1[0] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "===== Parametric Constructor =====" << std::endl;
    Array<int> test2(7);
    std::cout << "test2 size: " << test2.size() << std::endl;
    for(unsigned int i = 0; i < test2.size(); i++)
        std::cout << test2[i] << " ";
    std::cout << std::endl;
    std::cout << "===== Copy Constructor =====" << std::endl;
    Array<int> test3(test2);
    std::cout << "test3 size: " << test3.size() << std::endl;
    for(unsigned int i = 0; i < test3.size(); i++)
        std::cout << test3[i] << " ";
    std::cout << std::endl;
    std::cout << "===== Deep Copy (Copy Constructor) =====" << std::endl;
    test2[0] = 42;
    std::cout << "Test2 at index 0: " << test2[0];
    std::cout << "\nTest3 at index 0: " << test3[0];
    std::cout << std::endl;
    std::cout << "===== Assignment Operator =====" << std::endl;
    Array<int>test4(5);
    std::cout << "test4 before: " << test4.size() << std::endl;
    test4 = test2;
    std::cout << "test4 after: " << test4.size() << std::endl;
    std::cout << "===== Deep Copy (Assignment) =====" << std::endl;
    test4[0] = 999;
    std::cout << "Test4 at index 0: " << test4[0] << std::endl;
    std::cout << "Test2 at index 0: " << test2[0] << std::endl;
    std::cout << "===== Const Operator[] =====" << std::endl;
    const Array<int>test5(10);
    std::cout << "test5 size: " << test5.size() << std::endl;
    std::cout << "test5 index 0: " << test5[0] << std::endl;
    std::cout << "===== Another Type (string) =====" << std::endl;
    Array<std::string>test6(2);
    std::cout << "test6 size: " << test6.size() << std::endl;
    test6[0] = "hello";
    test6[1] = "world";
    std::cout << "First string: " << test6[0] << std::endl;
    std::cout << "Second string: " << test6[1] << std::endl;
    std::cout << "===== Out of Bounds =====" << std::endl;
    try
    {
        std::cout << test6[100] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}