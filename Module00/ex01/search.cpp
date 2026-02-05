/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 19:13:38 by msafa             #+#    #+#             */
/*   Updated: 2026/01/17 15:20:27 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static std::string truncate(const std::string &s){
    if(s.length() > 10)
        return s.substr(0,9) + ".";
    return s;
}


void PhoneBook::showContacts() const{
    
    if(contactCount == 0)
    {
        std::cout << "PhoneBook is empty. Please add a contact first" << std::endl;
        return ;
    }    
    std::string input;
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    for (int i = 0; i < contactCount;i++){
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << truncate(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << truncate(contacts[i].getLastName()) << "|"
                  << std::setw(10) << truncate(contacts[i].getNickname()) << std::endl;   
    }
    showContactDetails(contactCount);
}

void PhoneBook::showContactDetails(int count) const{
    std::string input;

    while(true)
    {
        std::cout << "Enter the index of the contact to view details: ";
        if(!std::getline(std::cin,input))
            break;
        if(input.empty())
        {
            std::cout << "Empty input..Please enter again" << std::endl;
            continue;
        }
        bool isNumber = true;
        for(size_t i = 0;i < input.length();i++)
        {
            if(!std::isdigit(input[i])){
                isNumber = false;
                break;
            }
        }
        if(!isNumber){
            std::cout << "Invalid index" << std::endl;
            continue;
        }
        std::stringstream ss(input);
        int idx;
        ss >> idx;
        if(idx >= count){
            std::cout << "Invalid index" << std::endl;
            continue ;
        }
        std::cout << "First Name: " << contacts[idx].getFirstName() << std::endl;
        std::cout << "Last Name: " << contacts[idx].getLastName() << std::endl;
        std::cout << "Nickname: " << contacts[idx].getNickname() << std::endl;
        std::cout << "Phone Number : " << contacts[idx].getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret : " << contacts[idx].getDarkestSecret() << std::endl;
        break;
    }
}
