/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 22:18:42 by msafa             #+#    #+#             */
/*   Updated: 2026/02/07 01:02:18 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat()
    :_name("default") , _grade (150)
{
    std::cout << "Bureaucrat default constructor called for " << _name << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
    :_name(src._name) , _grade(src._grade)
{
    std::cout << "Bureaucrat copy constructor called for " << _name << std::endl;

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
    if(this != &rhs)
        this->_grade = rhs._grade;
    std::cout << "Bureaucrat copy assignment operator called" << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called for " << _name << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
    :_name(name) , _grade(grade)
{
    if(_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if(grade > 150)
       throw Bureaucrat::GradeTooLowException();
    std::cout << "Bureaucrat parameterized constructor called for " << _name << std::endl;
}

std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::incrementGrade()
{
    if(this->_grade == 1)
       throw Bureaucrat::GradeTooHighException();
    else
        this->_grade -= 1;
}

void Bureaucrat::decrementGrade()
{
    if(this->_grade == 150)
      throw Bureaucrat::GradeTooLowException();
    else
        this->_grade += 1;
}

std::ostream& operator<<(std::ostream& os,const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
} 

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

void Bureaucrat::signForm(AForm& f)
{
    try
    {
        f.beSigned(*this);
        std::cout << this->_name << " signed " << f.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->_name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
    }
    
}

void Bureaucrat::executeForm(const AForm& form) const
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}