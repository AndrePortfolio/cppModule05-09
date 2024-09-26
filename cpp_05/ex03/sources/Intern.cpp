/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:32:24 by andre-da          #+#    #+#             */
/*   Updated: 2024/08/21 17:53:31 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*----------------------------------------------------------------------------*/
/*------------------------- Constructors & Destructor -----------------------*/
/*----------------------------------------------------------------------------*/

Intern::Intern()
{
	std::cout << "Intern Default Constructor called" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	*this = copy;

	std::cout << "Intern Copy Constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor called" << std::endl;
}

/*----------------------------------------------------------------------------*/
/*--------------------------------- Operator ---------------------------------*/
/*----------------------------------------------------------------------------*/

Intern &Intern::operator=(const Intern &other)
{
	if (this != &other)
	{
		*this = other;
	}
	std::cout << "Intern Copy Assignment Operator called" << std::endl;
	return (*this);
}

/*----------------------------------------------------------------------------*/
/*------------------------------ Member Functions ----------------------------*/
/*----------------------------------------------------------------------------*/

std::string	Intern::validNames[3] =
{
	"Presidential Pardon",
	"Robotomy Request",
	"Shrubbery Creation"
};

AForm	*(*Intern::formConstructors[3])(const std::string &target) =
{
	&ShrubberyCreationForm::create,
	&RobotomyRequestForm::create,
	&PresidentialPardonForm::create
};

AForm	*Intern::makeForm(const std::string &formName, const std::string &target)
{
	for (size_t i = 0; i < 3; i++)
	{
		if (validNames[i].compare(formName) == 0)
		{
			std::cout << "Intern creates " << formName << " form." << std::endl;
			return (formConstructors[i](target));
		}
	}
	throw FormNotFoundException();
}

const char	*Intern::FormNotFoundException::what() const throw()
{
	return ("Form not found!");
}
