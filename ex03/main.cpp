/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:34:43 by rhamini           #+#    #+#             */
/*   Updated: 2025/12/16 14:34:50 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Intern someRandomIntern;
		Bureaucrat jim("Jim", 1);

		Form *f1;
		Form *f2;
		Form *f3;

		std::cout << "\n--- Création des formulaires (devrait marcher) ---\n";
		f1 = someRandomIntern.makeForm("shrubbery creation", "Home");
		f2 = someRandomIntern.makeForm("robotomy request", "Bender");
		f3 = someRandomIntern.makeForm("presidential pardon", "Arthur");

		std::cout << "\n--- Signature + exécution par Jim (devrait marcher) ---\n";
		jim.signForm(*f1);
		jim.executeForm(*f1);

		jim.signForm(*f2);
		jim.executeForm(*f2);

		jim.signForm(*f3);
		jim.executeForm(*f3);

		delete f1;
		delete f2;
		delete f3;

		std::cout << "\n--- Création d'un formulaire inconnu (devrait échouer) ---\n";
		someRandomIntern.makeForm("unknown form", "Test");
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception attrapée : " << e.what() << std::endl;
	}
	return 0;
}
