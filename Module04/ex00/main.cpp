/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 20:23:18 by msafa             #+#    #+#             */
/*   Updated: 2026/02/01 23:01:56 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "wrongcat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << std::endl;
    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;

    std::cout << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    //test without virtual
    std::cout << std::endl;
    const WrongAnimal* safa = new WrongCat();
    std::cout << safa->getType() << std::endl;
    safa->makeSound();

    delete meta; delete j; delete i; delete safa;
    return 0;
}