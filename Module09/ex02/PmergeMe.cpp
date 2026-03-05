/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 20:42:13 by msafa             #+#    #+#             */
/*   Updated: 2026/03/05 02:53:34 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib> // for strtol
#include <climits> // INT_MAX
#include <iostream>

PmergeMe::PmergeMe()
    :_straggler(0),_hasStraggler(false)
{}

PmergeMe::~PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe& src)
    : _arr(src._arr),
      _pairs(src._pairs),
      _straggler(src._straggler),
      _hasStraggler(src._hasStraggler)
{}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
    if(this != &rhs)
    {
        this->_arr = rhs._arr;
        this->_pairs = rhs._pairs;
        this->_straggler = rhs._straggler;
        this->_hasStraggler = rhs._hasStraggler;
    }
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

void PmergeMe::buildPairs()
{
    for(size_t i = 0; i < this->_arr.size() - 1; i += 2)
    {
        int a = _arr[i];
        int b = _arr[i + 1];
        if(a > b)
            _pairs.push_back(std::make_pair(a,b));
        else
            _pairs.push_back(std::make_pair(b,a));
    }
    if(_arr.size() % 2 != 0)
    {
        _straggler = _arr.back();
        _hasStraggler = true;
    }
    for(size_t i = 0; i < _pairs.size(); i++)
        std::cout << "Pairs: " << _pairs[i].first << " " << _pairs[i].second << std::endl;
    if(_hasStraggler)
        std::cout << "straggler: " << _straggler << std::endl;
}


void PmergeMe::sort()
{
    buildPairs();
}