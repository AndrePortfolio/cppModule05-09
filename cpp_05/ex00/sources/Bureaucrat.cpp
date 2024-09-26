/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:32:24 by andre-da          #+#    #+#             */
/*   Updated: 2024/08/20 12:08:39 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*----------------------------------------------------------------------------*/
/*------------------------- Constructors & Destructor -----------------------*/
/*----------------------------------------------------------------------------*/

Bureaucrat::Bureaucrat() : name("Default"), grade(1)
{
	std::cout << "Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	std::cout << "Constructor called" << std::endl;

	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	std::cout << "Copy Constructor called" << std::endl;

	*this = copy;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called" << std::endl;
}

/*----------------------------------------------------------------------------*/
/*--------------------------------- Operator ---------------------------------*/
/*----------------------------------------------------------------------------*/

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Copy Assignment Operator called" << std::endl;

	if (this != &other)
	{
		if (other.grade < 1)
			throw GradeTooHighException();
		else if (other.grade > 150)
			throw GradeTooLowException();
		this->grade = other.grade;
	}
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
