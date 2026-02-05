/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:13:55 by msafa             #+#    #+#             */
/*   Updated: 2026/01/17 13:15:25 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class Contact {
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;
    public:
        void setFirstName(const std::string &str);
        void setLastName(const std::string &str);
        void setNickname(const std::string &str);
        void setPhoneNumber(const std::string &str);
        void setDarkestSecret(const std::string &str);
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickname() const;
        std::string getPhoneNumber() const;
        std::string getDarkestSecret() const;
};

class PhoneBook {
    private:
        Contact contacts[8];
        int index;
        int contactCount;
    public:
        PhoneBook();
        void addContact();
        void showContacts() const;
        void showContactDetails(int count) const;
};

#endif