/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 20:42:13 by msafa             #+#    #+#             */
/*   Updated: 2026/03/04 23:34:53 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib> // for strtol
#include <climits> // INT_MAX
#include <iostream>

PmergeMe::PmergeMe()
{}

PmergeMe::~PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe& src)
    :_arr(src._arr)
{}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
    if(this != &rhs)
        this->_arr = rhs._arr;
    return *this;
}

const char* PmergeMe::InvalidInput::what() const throw()
{
    return "Invalid input";
}

void PmergeMe::parse_and_validate(int argc, char *argv[])
{
    if(argc == 1)
        throw PmergeMe::InvalidInput();
    for(int i = 1; i < argc ;i++)
    {
        if(argv[i][0] == '\0')
            throw PmergeMe::InvalidInput();
        char *endptr;
        long nb = strtol(argv[i],&endptr,10);
        if(*endptr != '\0')
            throw PmergeMe::InvalidInput();
        if(nb <= 0)
            throw PmergeMe::InvalidInput();
        if(nb > INT_MAX)
            throw PmergeMe::InvalidInput();
        this->_arr.push_back(static_cast<int>(nb));
    }
}

void PmergeMe::display_arr(std::string const& label) const
{
    std::cout << label;
    for(size_t i = 0; i < this->_arr.size(); i++)
        std::cout << " " << this->_arr[i];
    std::cout << std::endl;
}

void PmergeMe::sort()
{
    
}