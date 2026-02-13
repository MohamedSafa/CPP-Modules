/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 23:43:13 by msafa             #+#    #+#             */
/*   Updated: 2026/02/05 23:41:38 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>


class Bureaucrat
{
	private:
	std::string const _name;
	int _grade;
	
	public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& src);
	Bureaucrat &operator=(const Bureaucrat& rhs);
	~Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	
	class GradeTooHighException : public std::exception{
			public:
				const char* what() const throw();
		};
	
	class GradeTooLowException : public std::exception 
	{
		public:
			const char* what() const throw();
	};
	std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
};

std::ostream&  operator<<(std::ostream& os,const Bureaucrat& b);

#endif
