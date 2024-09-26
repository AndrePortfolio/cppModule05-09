/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:32:24 by andre-da          #+#    #+#             */
/*   Updated: 2024/08/21 18:06:25 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int main()
{
	srand(time(0));
	try
	{
		Intern		intern;
		Bureaucrat	boss("Boss", 1);

		std::cout << std::endl << GREEN << "SHRUBBERY" << RESET << std::endl;
		AForm	*form1 = intern.makeForm("Shrubbery Creation", "Garden");
		std::cout << "\n";
		if (form1)
		{
			boss.signForm(*form1);
			boss.executeForm(*form1);
			delete form1;
		}
		std::cout << std::endl << GREEN << "ROBOTOMY" << RESET << std::endl;
		AForm	*form2 = intern.makeForm("Robotomy Request", "Bender");
		std::cout << "\n";
		if (form2)
		{
			boss.signForm(*form2);
			boss.executeForm(*form2);
			delete form2;
		}
		std::cout << std::endl << GREEN << "PRESIDENTIAL" << RESET << std::endl;
		AForm	*form3 = intern.makeForm("Presidential Pardon", "Zaphod Beeblebrox");
		std::cout << "\n";
		if (form3)
		{
			boss.signForm(*form3);
			boss.executeForm(*form3);
			delete form3;
		}
		std::cout << std::endl << RED << "INVALID FORM" << RESET << std::endl;
		AForm* invalidForm = intern.makeForm("invalid form name", "Nobody");
		if (invalidForm)
			delete invalidForm;

	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
