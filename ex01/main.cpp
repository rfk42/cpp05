/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:54:28 by rhamini           #+#    #+#             */
/*   Updated: 2025/12/02 13:41:43 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try {
        Bureaucrat bob("Bob", 50);
        Bureaucrat jim("Jim", 1);

        Form f1("Formulaire_A", 100, 50);
        Form f2("Formulaire_B", 20, 10);

        std::cout << bob << std::endl;
        std::cout << jim << std::endl;

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;

        std::cout << "\n--- Tentative de signature par Bob (devrait marcher pour f1) ---\n";
        bob.signForm(f1);

        std::cout << "\n--- Tentative de signature par Bob (devrait échouer pour f2) ---\n";
        bob.signForm(f2);

        std::cout << "\n--- Tentative de signature par Jim (devrait marcher pour tout) ---\n";
        jim.signForm(f2);

        std::cout << "\n--- États finaux ---\n";
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Exception attrapée : " << e.what() << std::endl;
    }

    return 0;
}

