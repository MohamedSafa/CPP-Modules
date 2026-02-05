/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 20:23:18 by msafa             #+#    #+#             */
/*   Updated: 2026/02/02 01:13:26 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "wrongcat.hpp"
#include "brain.hpp"

int main()
{
    // subject main
    const Animal* j = new Dog();
    std::cout << std::endl;
    
    const Animal* i = new Cat();
    std::cout << std::endl;
    
    delete j;
    delete i;
    // my tests
    const  int size = 10;
    Animal* animals[size];

    for(int i = 0; i < size / 2; i++)
    {
        animals[i] = new Dog();
        std::cout << std::endl;
    }
    for(int i = size / 2; i < size; i++)
    {
        animals[i] = new Cat();
        std::cout << std::endl; 
    }

    for(int i = 0; i < size; i++)
        delete animals[i];

    // deep copy test
    Dog dog1;
    dog1.setIdea(0,"barking");
    Dog dog2(dog1);
    dog1.makeSound();
    dog2.makeSound();
    std::cout << std::endl;
    // another deep copy test for seperate brains
    
    std::cout << "dog1 idea: " << dog1.getIdea(0) << std::endl;
    std::cout << "dog2 idea: " << dog2.getIdea(0) << std::endl;
    dog1.setIdea(0,"meowing");
    std::cout << "dog1 idea: " << dog1.getIdea(0) << std::endl;
    std::cout << "dog2 idea: " << dog2.getIdea(0) << std::endl;
    return 0;
}