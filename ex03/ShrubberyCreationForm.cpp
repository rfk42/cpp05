/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:56:52 by rhamini           #+#    #+#             */
/*   Updated: 2025/12/12 14:56:53 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: Form("ShrubberyCreationForm", 145, 137), target("Default")
{
	std::cout << "ShrubberyCreationForm default constructor has been called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: Form("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "Constructor ShrubberyCreationForm has been called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: Form(src), target(src.target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src)
	{
		Form::operator=(src);
		this->target = src.target;
	}
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm has been destroyed" << std::endl;
}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream file((target + "_shrubbery").c_str());
	if (!file.is_open())
		return;

	file << "   /\\   " << std::endl;
	file << "  /\\*\\  " << std::endl;
	file << " /\\O\\*\\ " << std::endl;
	file << "   ||   " << std::endl;
	file.close();
}
