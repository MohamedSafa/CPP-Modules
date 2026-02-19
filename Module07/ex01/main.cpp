/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:49:36 by msafa             #+#    #+#             */
/*   Updated: 2026/02/14 20:27:34 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void increment(int& element)
{
    element++;
}

void print(const int& element)
{
    std::cout << element << std::endl;
}

template <typename T>
void printstr(T const& str)
{
    std::cout << str << std::endl;
}

int main(void)
{
    // test 1 (non const arr)
    int arr1[3] = {1 , 2 , 3};
    iter(arr1,3,increment);
    std::cout << "arr[0] = " << arr1[0] << std::endl;
    std::cout << "arr[1] = " << arr1[1] << std::endl;
    std::cout << "arr[2] = " << arr1[2] << std::endl;
    // test2 (const arr)
    const int arr2[3] = {1, 2, 3};
    iter(arr2,3,print);
    // test 3(function template)
    std::string arr3[] = {"hello","world"};
    iter(arr3,2,printstr<std::string>);
    return 0;
}   