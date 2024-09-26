/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:32:24 by andre-da          #+#    #+#             */
/*   Updated: 2024/08/21 13:50:15 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int main()
{
	srand(time(0));
	try
	{
		std::cout << YELLOW << "CONTRUCTORS\n" << RESET;

		// AForm	form;
		Bureaucrat	bob("Bob", 5);
		Bureaucrat	alice("Alice", 150);
		Bureaucrat	mark("Mark", 1);
		std::cout << "\n";
		PresidentialPardonForm	f1("f1");
		std::cout << "\n";
		RobotomyRequestForm		f2("f2");
		std::cout << "\n";
		ShrubberyCreationForm	f3("f3");

		std::cout << CYAN << "\nDISPLAY INITIALIZATIONS\n"  << RESET;
		std::cout << bob << mark << alice << f1 << f2 << f3;

		std::cout << GREEN << "\nPRESIDENTIAL TESTS\n" << RESET;
		std::cout << f1 << GREEN << "1. " << RESET;
		alice.signForm(f1);
		std::cout << GREEN << "2. " << RESET;
		mark.executeFrom(f1);
		std::cout << GREEN << "3. " << RESET;
		mark.signForm(f1);
		std::cout << GREEN << "4. " << RESET;
		bob.executeFrom(f1);

		std::cout << GREEN << "\nROBOTOMY TESTS\n" << RESET;
		std::cout << f2 << GREEN << "1. " << RESET;
		alice.signForm(f2);
		std::cout << GREEN << "2. " << RESET;
		mark.executeFrom(f2);
		std::cout << GREEN << "3. " << RESET;
		mark.signForm(f2);
		std::cout << GREEN << "4. " << RESET;
		bob.executeFrom(f2);

		std::cout << GREEN << "\nSHRYBBERY TESTS\n" << RESET;
		std::cout << f3 << GREEN << "1. " << RESET;
		alice.signForm(f3);
		std::cout << GREEN << "2. " << RESET;
		mark.executeFrom(f3);
		std::cout << GREEN << "3. " << RESET;
		mark.signForm(f3);
		std::cout << GREEN << "4. " << RESET;
		bob.executeFrom(f3);

		// Bureaucrat	john("John", 0);
		// Bureaucrat	luis("Luis", 151);

		std::cout << YELLOW << "\nDESTRUCTORS\n" << RESET;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
