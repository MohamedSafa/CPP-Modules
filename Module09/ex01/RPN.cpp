/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 23:02:34 by msafa             #+#    #+#             */
/*   Updated: 2026/02/26 12:33:36 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <iostream>

RPN::RPN()
{}

RPN::~RPN()
{}

RPN::RPN(const RPN& src)
    :_stack(src._stack)
{}

RPN& RPN::operator=(const RPN& rhs)
{
    if(this != &rhs)
        this->_stack = rhs._stack;
    return *this;
}

void RPN::calculate(const std::string& formula)
{
    std::string nb;
    std::stringstream ss(formula);
    while(ss >> nb)
    {
        if(nb.size() == 1 && isdigit(nb[0]))
            this->_stack.push(nb[0] - '0');
        else if(nb == "*" || nb == "+" || nb == "-" || nb == "/") 
        {
            if(_stack.size() < 2)
            {
                std::cerr << "Error: invalid input" << std::endl;
               return ;
            }
            int a = _stack.top();
            _stack.pop();
            int b = _stack.top();
            _stack.pop();
            if(nb == "*")
                this->_stack.push(a * b);
            else if(nb == "+")
                this->_stack.push(a + b);
            else if(nb == "-")
                this->_stack.push(b - a);
            else if(nb == "/")
            {
                if(a == 0)
                {
                    std::cerr << "Error: can't divide by 0" << std::endl;
                    return ;
                }
                this->_stack.push(b / a);
            }
        }
        else
        {
            std::cerr << "Error: invalid input" << std::endl;
            return;
        }
    }
    if(this->_stack.size() == 1)
        std::cout << this->_stack.top() << std::endl;
    else
        std::cerr << "Error: invalid input" << std::endl;
} 