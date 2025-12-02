/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:54:28 by rhamini           #+#    #+#             */
/*   Updated: 2025/11/22 18:57:06 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "---- Test de creation valide ----" << std::endl;
	try {
		Bureaucrat b1("Alice", 1);
		Bureaucrat b2("Bob", 150);

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;

		std::cout << "---- Test incrémentation ----" << std::endl;
		b2.incrementGrade();
		std::cout << b2 << std::endl;

		std::cout << "---- Test décrémentation ----" << std::endl;
		b1.decrementGrade();
		std::cout << b1 << std::endl;

	} catch (std::exception &e) {
		std::cout << "Exception attrapée : " << e.what() << std::endl;
	}

	std::cout << "\n---- Test creation invalide (grade trop haut) ----" << std::endl;
	try {
		Bureaucrat b3("Charles", 0); // Trop haut
	} catch (std::exception &e) {
		std::cout << "Exception attrapée : " << e.what() << std::endl;
	}

	std::cout << "\n---- Test creation invalide (grade trop bas) ----" << std::endl;
	try {
		Bureaucrat b4("David", 200); // Trop bas
	} catch (std::exception &e) {
		std::cout << "Exception attrapée : " << e.what() << std::endl;
	}

	std::cout << "\n---- Test incrémentation impossible ----" << std::endl;
	try {
		Bureaucrat b5("Edgar", 1);
		b5.incrementGrade();  // Devrait lancer GradeTooHighException
	} catch (std::exception &e) {
		std::cout << "Exception attrapée : " << e.what() << std::endl;
	}

	std::cout << "\n---- Test décrémentation impossible ----" << std::endl;
	try {
		Bureaucrat b6("Frank", 150);
		b6.decrementGrade();  // Devrait lancer GradeTooLowException
	} catch (std::exception &e) {
		std::cout << "Exception attrapée : " << e.what() << std::endl;
	}

	return 0;
}
