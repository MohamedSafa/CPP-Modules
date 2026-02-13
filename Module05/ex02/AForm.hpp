/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 20:36:31 by msafa             #+#    #+#             */
/*   Updated: 2026/02/06 22:47:56 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeTosign;
        const int _gradeToexecute;
    public:
        AForm();
        AForm(const AForm& src);
        AForm& operator=(const AForm& rhs);
        virtual ~AForm();
        AForm(const std::string& name, int gradeToSign, int gradeToExecute);
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        std::string getName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(const Bureaucrat& b);
        void execute(const Bureaucrat& executor) const;
        virtual void executeAction() const = 0;
};

std::ostream& operator<<(std::ostream& os,const AForm& f);

#endif