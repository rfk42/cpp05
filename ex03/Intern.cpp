/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:35:04 by rhamini           #+#    #+#             */
/*   Updated: 2025/12/16 14:35:07 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor has been called" << std::endl;
}

Intern::Intern(const Intern &src)
{
	(void)src;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &src)
{
	(void)src;
	std::cout << "Intern copy assignment operator called" << std::endl;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern has been destroyed" << std::endl;
}

static Form *createShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static Form *createRobotomy(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static Form *createPresidential(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

Form *Intern::makeForm(const std::string name, const std::string target)
{
	const std::string forms[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	Form *(*creator[3])(const std::string) = {
		&createShrubbery,
		&createRobotomy,
		&createPresidential
	};

	int i = 0;
	while (i < 3)
	{
		if (forms[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return (creator[i](target));
		}
		i++;
	}
	throw FormNotFoundException();
}


const char *Intern::FormNotFoundException::what() const throw()
{
	return ("form not found");
}
