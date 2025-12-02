/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:19:31 by rhamini           #+#    #+#             */
/*   Updated: 2025/12/02 13:43:56 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default"), sign(false), signGrade(1), execGrade(1)
{
	std::cout << "Form default constructor has been called" << std::endl;
}

Form::Form(const std::string name, const int signGrade, const int execGrade) : name(name), sign(false), signGrade(signGrade), execGrade(execGrade)
{
	std::cout << "Constructor " << name << " has been called" << std::endl;
}

Form::Form(const Form &src) : name(src.name), sign(src.sign), signGrade(src.signGrade), execGrade(src.execGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &src)
{
	if (this != &src)
		this->sign = src.sign;
	std::cout << "Form copy assignment operator called" << std::endl;
	return *this;
}

Form::~Form()
{
	std::cout << "Form " << name << " has been destroyed" << std::endl;
}

void	Form::beSigned(Bureaucrat const &src)
{
	if (src.getGrade() <= signGrade)
		sign = true;
	else
		throw GradeTooLowException();
}

std::string const Form::getName() const
{
	return (this->name);
}

bool	Form::getSigned() const
{
	return (this->sign);
}

int	Form::getSignGrade() const
{
	return (this->signGrade);
}

int	Form::getExecGrade() const
{
	return (this->execGrade);
}

const char * Form::GradeTooHighException::what() const throw()
{
	return ("grade is too High");
}

const char * Form::GradeTooLowException::what() const throw()
{
	return ("grade is too Low");
}

std::ostream &operator<<(std::ostream &os, Form const &src)
{
	os << src.getName() << ", Signed : " << src.getSigned() << ", SignGrade : " << src.getSignGrade() << ", ExecGrade : " << src.getExecGrade() << std::endl;
	return (os);
}