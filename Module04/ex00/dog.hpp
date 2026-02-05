/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 20:33:55 by msafa             #+#    #+#             */
/*   Updated: 2026/01/31 23:15:29 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "animal.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(const Dog& src);
        Dog& operator=(const Dog& rhs);
        ~Dog();
        void makeSound() const;
};

#endif