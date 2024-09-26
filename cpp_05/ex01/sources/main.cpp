/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:32:24 by andre-da          #+#    #+#             */
/*   Updated: 2024/08/20 16:30:27 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int main()
{
	try
	{
		std::cout << YELLOW << "CONTRUCTORS\n" << RESET;
		
		Bureaucrat	bob("Bob", 10);
		Bureaucrat	alice("Alice", 30);
		Form		taxForm("Tax Form", 20, 50);
		Form		vatForm("Vat Form", 140, 2);

		std::cout << CYAN << "\nDISPLAY INITIALIZATIONS\n"  << RESET;
		std::cout << bob << alice << taxForm << vatForm;

		std::cout << GREEN << "\nEXAMPLES WORKING\n1. " << RESET;
		bob.signForm(taxForm);
		std::cout << taxForm << GREEN << "2. " << RESET;
		alice.signForm(vatForm);
		std::cout << vatForm << "\n";

		std::cout << RED << "EXAMPLE NOT WORKING\n1. " << RESET;
		alice.signForm(taxForm);
		std::cout << vatForm;

		// Form		wrongForm1("Wrong Form1", 151, 2);
		// Form		wrongForm2("Wrong Form2", 0, 2);
		// Form		wrongForm3("Wrong Form3", 2, 151);
		// Form		wrongForm4("Wrong Form4", 2, 0);

		std::cout << YELLOW << "\nDESTRUCTORS\n" << RESET;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
