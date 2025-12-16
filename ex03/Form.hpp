#ifndef FORM_HPP
#define	FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string const	name;
	bool				sign;
	int const			signGrade;
	int const			execGrade;

public:
	Form();
	Form(const std::string name, const int signGrade, const int execGrade);
	Form(const Form &src);
	Form &operator=(const Form &src);
	virtual ~Form();

	std::string const	getName() const;
	bool				getSigned() const;
	int					getSignGrade() const;
	int					getExecGrade() const;

	void				beSigned(Bureaucrat const &src);
	void				execute(Bureaucrat const &executor) const;

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

protected:
	virtual void		executeAction() const = 0;
};

std::ostream &operator<<(std::ostream &os, Form const &src);

#endif
