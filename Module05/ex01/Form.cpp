/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 00:28:46 by msafa             #+#    #+#             */
/*   Updated: 2026/02/05 23:15:56 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
    :_name("default") , _signed(false), _gradeTosign(150),_gradeToexecute(150)
{
    std::cout << "Form " << this->getName() << " default constructor called" << std::endl;
}

Form::Form(const Form& src)
    :_name(src._name) , _gradeTosign(src._gradeTosign),_gradeToexecute(src._gradeToexecute)
{
    this->_signed = src._signed;
    std::cout << "Form " << this->getName() << " copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& rhs)
{
    if(this != &rhs)
        this->_signed = rhs._signed;
    std::cout << "Form " << this->getName() << " assignment operator called" << std::endl;
    return *this;
}

Form::~Form()
{
    std::cout << "Form " << this->getName() << " destructor called" << std::endl;
}

Form::Form(const std::string& name, int gradeTosign,int gradeToexecute)
    :_name(name) , _gradeTosign(gradeTosign) , _gradeToexecute(gradeToexecute)
{
    this->_signed = false;
    if(this->_gradeTosign < 1 || this->_gradeToexecute < 1)
        throw GradeTooHighException();
    if(this->_gradeToexecute > 150 || this->_gradeTosign > 150)
        throw GradeTooLowException();
    std::cout << "Form " << this->getName() << " parameterized constructor called" << std::endl;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form's grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form's grade is too low";
}

std::string Form::getName() const
{
    return this->_name;
}

bool Form::getSigned() const
{
    return this->_signed;
}

int Form::getGradeToSign() const
{
    return this->_gradeTosign;
}

int Form::getGradeToExecute() const
{
    return this->_gradeToexecute;
}

void Form::beSigned(const Bureaucrat& b)
{
    if(b.getGrade() <= this->_gradeTosign)
        this->_signed = true;
    else
        throw Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os,const Form& f)
{
    os << f.getName();
    if(f.getSigned())
        os << " is signed";
    else
        os << " is not signed yet!" << std::endl;
    os << "(Grade to sign: " << f.getGradeToSign() << ")" << std::endl
       << "(Grade to execute: " << f.getGradeToExecute() << ")";
       return os;
}
