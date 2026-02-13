/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:38:45 by msafa             #+#    #+#             */
/*   Updated: 2026/02/07 19:57:22 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

struct Functs
{
    std::string name;
    AForm* (*create)(const std::string& target);
};

class Intern
{
    private:
        static AForm* createShrubbery(const std::string& target);
        static AForm* createRobotomy(const std::string& target);
        static AForm* createPresidential(const std::string& target);
    public:
        Intern();
        ~Intern();
        Intern(const Intern& src);
        Intern& operator=(const Intern& rhs);
        AForm* makeForm(const std::string& form,const std::string& target);
};

#endif