/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:38:18 by msafa             #+#    #+#             */
/*   Updated: 2026/02/14 18:36:01 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T& a,T& b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}
template <typename T>
T const& min(T const& a,T const& b)
{
    if(a < b)
        return a;
    return b;
}

template <typename T>
T const& max(T const& a,T const& b)
{
    if(a > b)
        return a;
    return b;
}

#endif