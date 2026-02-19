/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 20:31:53 by msafa             #+#    #+#             */
/*   Updated: 2026/02/15 00:50:11 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
    private:
        T* array;
        unsigned int n;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& src);
        ~Array();
        Array& operator=(const Array& rhs);
        const T& operator[](unsigned int idx) const;
        T& operator[](unsigned int idx);
        unsigned int size() const;
};

#include "Array.tpp"

#endif