/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 20:49:01 by msafa             #+#    #+#             */
/*   Updated: 2026/02/19 20:43:08 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container,int value)
{
    typename T::iterator first_occurrence;
    first_occurrence = std::find(container.begin() ,container.end(),value);
    if(first_occurrence != container.end())
        return first_occurrence;
    else
        throw std::runtime_error("Value not found");
}