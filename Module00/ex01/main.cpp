/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:36:07 by msafa             #+#    #+#             */
/*   Updated: 2026/01/17 15:20:10 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
    contactCount = 0;
    index = 0;
}

int main(){
    PhoneBook phonebook;
    std::string command;

    while(std::cin){
        std::cout << "Enter one of the following commands: ADD, SEARCH , EXIT: ";
        if(!std::getline(std::cin,command))
            break;
        if(command == "ADD"){
            phonebook.addContact();
        }else if(command == "SEARCH"){
            phonebook.showContacts();
        }else if(command == "EXIT"){
            break;
        }
    }
    return(0);
}
