/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 00:00:18 by msafa             #+#    #+#             */
/*   Updated: 2026/01/17 15:20:22 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::addContact(){
    Contact c;
    std::string input;
    
    std::cout << "First Name: ";
    if(!std::getline(std::cin,input) || input.empty())
        return ;
    c.setFirstName(input);

    std::cout << "Last Name: ";
    if(!std::getline(std::cin,input) || input.empty())
        return ;
    c.setLastName(input);
    
    std::cout << "Nickname: ";
    if(!std::getline(std::cin,input) || input.empty())
        return;
    c.setNickname(input);

    std::cout << "Phone Number: ";
    if(!std::getline(std::cin,input) || input.empty())
        return;
    c.setPhoneNumber(input);

    std::cout << "Darkest Secret: ";
    if(!std::getline(std::cin,input) || input.empty())
        return;
    c.setDarkestSecret(input);

    contacts[index] = c;
    if(contactCount < 8)
        contactCount++;
    index++;
    if(index > 7)
        index = 0;
}
