/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 23:02:32 by msafa             #+#    #+#             */
/*   Updated: 2026/02/21 23:36:20 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN
{
    private:
        std::stack<int> _stack;
    public:
        RPN();
        ~RPN();
        RPN(const RPN& src);
        RPN& operator=(const RPN& rhs);
        void calculate(const std::string& formula);
};

#endif