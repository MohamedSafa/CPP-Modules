/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:51:32 by msafa             #+#    #+#             */
/*   Updated: 2026/02/17 19:32:35 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
    private:
        std::vector<int> container;
        unsigned int _n;
    public:
        Span();
        ~Span();
        Span(const Span& src);
        Span& operator=(const Span& rhs);
        Span(unsigned int n);
        void addNumber(int n);
        template <typename Iterator>
        void addRange(Iterator begin, Iterator end);
        int shortestSpan() const;
        int longestSpan() const;
};

template<typename Iterator>
void Span::addRange(Iterator begin,Iterator end)
{
    while(begin != end)
    {
        addNumber(*begin);
        begin++;
    }
}

#endif