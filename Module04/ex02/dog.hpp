/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 20:33:55 by msafa             #+#    #+#             */
/*   Updated: 2026/02/01 23:30:05 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "animal.hpp"
#include "brain.hpp"

class Dog : public Animal
{
    private:
        Brain* brain;
    public:
        Dog();
        Dog(const Dog& src);
        Dog& operator=(const Dog& rhs);
        ~Dog();
        void makeSound() const;
        void setIdea(int index, std::string idea);
        std::string getIdea(int index) const;
};

#endif