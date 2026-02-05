/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 20:33:49 by msafa             #+#    #+#             */
/*   Updated: 2026/01/31 23:28:31 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat& src);
        Cat& operator=(const Cat& rhs);
        ~Cat();
        void makeSound() const;
};

#endif