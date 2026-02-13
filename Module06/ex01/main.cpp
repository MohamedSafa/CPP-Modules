/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 14:07:18 by msafa             #+#    #+#             */
/*   Updated: 2026/02/13 14:43:20 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data data;   
    data.name = "safa";
    data.value = 42;
    
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Pointer: " << &data << std::endl;
    std::cout << "Pointer as uintptr_t: " << raw << std::endl;
    Data* test = Serializer::deserialize(raw);
    std::cout << "Test address after deserializing the raw value: " << test << std::endl;
    std::cout << "Same address: " << (test == &data ? "YES" : "NO") << std::endl;
    std::cout << "Name: " << test->name << std::endl;
    std::cout << "Value: " << test->value << std::endl;
    return 0;
}
