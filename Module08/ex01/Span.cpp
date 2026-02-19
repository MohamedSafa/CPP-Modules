/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:51:29 by msafa             #+#    #+#             */
/*   Updated: 2026/02/18 20:55:01 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <stdexcept>

Span::Span()
    :_n(0)
{}

Span::~Span()
{}

Span::Span(const Span& src)
    :container(src.container) , _n(src._n)
{}

Span& Span::operator=(const Span& rhs)
{
    if(this != &rhs)
    {
        this->container = rhs.container;
        this->_n = rhs._n;
    }
    return *this;
}

Span::Span(unsigned int n)
{
    this->_n = n;
}

void Span::addNumber(int n)
{
    if(this->container.size() >= this->_n)
        throw std::runtime_error("The span is already filled");
    container.push_back(n);
}

int Span::longestSpan() const
{
    if(this->container.size() < 2)
        throw std::runtime_error("Not enough integers");
    std::vector<int>::const_iterator min = std::min_element(this->container.begin(),this->container.end());
    std::vector<int>::const_iterator max = std::max_element(this->container.begin(),this->container.end());
    return *max - *min;
}

int Span::shortestSpan() const
{
    std::vector<int> copy;
     if(this->container.size() < 2)
        throw std::runtime_error("Not enough integers");
    copy = this->container;
    std::sort(copy.begin(),copy.end());
    int min = copy[1] - copy[0];
    for(size_t i = 1 ;i < copy.size() ; i++)
    {
        if((copy[i] - copy[i - 1]) < min)
            min = copy[i] - copy[i - 1]; 
    }
    return min;
}