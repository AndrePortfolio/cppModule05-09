/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:32:24 by andre-da          #+#    #+#             */
/*   Updated: 2024/08/21 13:34:22 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*----------------------------------------------------------------------------*/
/*------------------------- Constructors & Destructor -----------------------*/
/*----------------------------------------------------------------------------*/

Bureaucrat::Bureaucrat() : name("Default"), grade(1)
{
	std::cout << "Bureaucrat Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();

	std::cout << "Bureaucrat Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	*this = copy;

	std::cout << "Bureaucrat Copy Constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

/*----------------------------------------------------------------------------*/
/*--------------------------------- Operator ---------------------------------*/
/*----------------------------------------------------------------------------*/

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		if (other.grade < 1)
			throw GradeTooHighException();
		else if (other.grade > 150)
			throw GradeTooLowException();
		this->grade = other.grade;
	}
	std::cout << "Bureaucrat Copy Assignment Operator called" << std::endl;
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade "
		<< bureaucrat.getGrade() << "." << std::endl;

	return (out);
}

/*----------------------------------------------------------------------------*/
/*------------------------------ Member Functions ----------------------------*/
/*----------------------------------------------------------------------------*/

const std::string	&Bureaucrat::getName() const
{
	return (this->name);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

void	Bureaucrat::incrementGrade(int amount)
{
	grade -= amount;
	if (grade < 1)
		throw GradeTooHighException();
}

void	Bureaucrat::decrementGrade(int amount)
{
	grade += amount;
	if (grade > 150)
		throw GradeTooLowException();
}

void	Bureaucrat::signForm(AForm &aForm)
{
	try
	{
		aForm.beSigned(*this);
		std::cout << name << " signed " << aForm.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << name << " couldn't sign " << aForm.getName()
			<< " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeFrom(AForm const &form)
{
	try
	{
		form.execute(*this);

		std::cout << name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << name << " could not execute "
			<< form.getName() << " because " << e.what() << std::endl;
	}
}

/*----------------------------------------------------------------------------*/
/*--------------------------- Exception Definitions --------------------------*/
/*----------------------------------------------------------------------------*/

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too High!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too Low!");
}
