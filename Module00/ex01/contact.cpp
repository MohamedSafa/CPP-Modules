/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:34:14 by msafa             #+#    #+#             */
/*   Updated: 2026/01/16 21:04:12 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

//setters

void Contact::setFirstName(const std::string &str){
    firstName = str;
}

void Contact::setLastName(const std::string &str){
    lastName = str;
}

void Contact::setNickname(const std::string &str){
    nickName = str;
}

void Contact::setPhoneNumber(const std::string &str){
    phoneNumber = str;
}

void Contact::setDarkestSecret(const std::string &str){
    darkestSecret = str;
}

//getters

std::string Contact::getFirstName() const{
    return firstName;
}

std::string Contact::getLastName() const{
    return lastName;
}

std::string Contact::getNickname() const{
    return nickName;
}

std::string Contact::getPhoneNumber() const{
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const{
    return darkestSecret;
}
