/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:54:28 by rhamini           #+#    #+#             */
/*   Updated: 2025/12/12 15:00:31 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat bob("Bob", 50);
		Bureaucrat jim("Jim", 1);
		Bureaucrat low("Low", 150);

		ShrubberyCreationForm f1("Home");
		RobotomyRequestForm f2("Bender");
		PresidentialPardonForm f3("Arthur");

		std::cout << bob << std::endl;
		std::cout << jim << std::endl;
		std::cout << low << std::endl;

		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
		std::cout << f3 << std::endl;

		std::cout << "\n--- Tentative d'exécution sans signature (devrait échouer) ---\n";
		bob.executeForm(f1);

		std::cout << "\n--- Signature par Bob (devrait marcher pour Shrubbery) ---\n";
		bob.signForm(f1);

		std::cout << "\n--- Exécution par Bob (devrait marcher pour Shrubbery) ---\n";
		bob.executeForm(f1);

		std::cout << "\n--- Signature par Low (devrait échouer pour Robotomy et Presidential) ---\n";
		low.signForm(f2);
		low.signForm(f3);

		std::cout << "\n--- Signature par Bob (devrait marcher pour Robotomy) ---\n";
		bob.signForm(f2);

		std::cout << "\n--- Exécution par Bob (devrait échouer pour Robotomy, grade trop bas) ---\n";
		bob.executeForm(f2);

		std::cout << "\n--- Exécution par Jim (devrait marcher pour Robotomy, résultat 50/50) ---\n";
		jim.executeForm(f2);
		jim.executeForm(f2);

		std::cout << "\n--- Signature + exécution Presidential par Jim (devrait marcher) ---\n";
		jim.signForm(f3);
		jim.executeForm(f3);

		std::cout << "\n--- États finaux ---\n";
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
		std::cout << f3 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception attrapée : " << e.what() << std::endl;
	}
	return 0;
}
