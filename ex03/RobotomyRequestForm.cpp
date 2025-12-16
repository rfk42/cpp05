/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:57:33 by rhamini           #+#    #+#             */
/*   Updated: 2025/12/12 14:57:36 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
	: Form("RobotomyRequestForm", 72, 45), target("Default")
{
	std::cout << "RobotomyRequestForm default constructor has been called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: Form("RobotomyRequestForm", 72, 45), target(target)
{
	std::cout << "Constructor RobotomyRequestForm has been called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: Form(src), target(src.target)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src)
	{
		Form::operator=(src);
		this->target = src.target;
	}
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm has been destroyed" << std::endl;
}

void RobotomyRequestForm::executeAction() const
{
	static int seeded = 0;

	if (seeded == 0)
	{
		std::srand(std::time(NULL));
		seeded = 1;
	}
	std::cout << "* drilling noises *" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << target << " has been robotomized successfully" << std::endl;
	else
		std::cout << target << " robotomy failed" << std::endl;
}
