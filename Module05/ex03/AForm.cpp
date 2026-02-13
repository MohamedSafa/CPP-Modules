/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 20:36:29 by msafa             #+#    #+#             */
/*   Updated: 2026/02/06 23:08:32 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    :_name("default") , _signed(false), _gradeTosign(150),_gradeToexecute(150)
{
    std::cout << "AForm " << this->getName() << " default constructor called" << std::endl;
}

AForm::AForm(const AForm& src)
    :_name(src._name) , _gradeTosign(src._gradeTosign),_gradeToexecute(src._gradeToexecute)
{
    this->_signed = src._signed;
    std::cout << "AForm " << this->getName() << " copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& rhs)
{
    if(this != &rhs)
        this->_signed = rhs._signed;
    std::cout << "AForm " << this->getName() << " assignment operator called" << std::endl;
    return *this;
}

AForm::~AForm()
{
    std::cout << "AForm " << this->getName() << " destructor called" << std::endl;
}

AForm::AForm(const std::string& name, int gradeTosign,int gradeToexecute)
    :_name(name) , _gradeTosign(gradeTosign) , _gradeToexecute(gradeToexecute)
{
    this->_signed = false;
    if(this->_gradeTosign < 1 || this->_gradeToexecute < 1)
        throw GradeTooHighException();
    if(this->_gradeToexecute > 150 || this->_gradeTosign > 150)
        throw GradeTooLowException();
    std::cout << "AForm " << this->getName() << " parameterized constructor called" << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm's grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm's grade is too low";
}

std::string AForm::getName() const
{
    return this->_name;
}

bool AForm::getSigned() const
{
    return this->_signed;
}

int AForm::getGradeToSign() const
{
    return this->_gradeTosign;
}

int AForm::getGradeToExecute() const
{
    return this->_gradeToexecute;
}

void AForm::beSigned(const Bureaucrat& b)
{
    if(b.getGrade() <= this->_gradeTosign)
        this->_signed = true;
    else
        throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os,const AForm& f)
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

void AForm::execute(const Bureaucrat& executor) const
{
    if(!this->getSigned())
        throw std::runtime_error("Form is not signed!");
    if(executor.getGrade() > this->getGradeToExecute())
        throw  AForm::GradeTooLowException();
    this->executeAction();
}