/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:32:24 by andre-da          #+#    #+#             */
/*   Updated: 2024/08/21 13:48:35 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*----------------------------------------------------------------------------*/
/*------------------------- Constructors & Destructor -----------------------*/
/*----------------------------------------------------------------------------*/

AForm::AForm() : name("Default"), isSigned(false), signGrade(1), executeGrade(1)
{
	std::cout << "AForm Default Constructor called" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int executeGrade)
	: name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();

	std::cout << "AForm Constructor called" << std::endl;
}

AForm::AForm(const AForm &copy) : name(copy.name), isSigned(copy.isSigned),
	signGrade(copy.signGrade), executeGrade(copy.executeGrade)
{
	std::cout << "AForm Copy Constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm Destructor called" << std::endl;
}

/*----------------------------------------------------------------------------*/
/*--------------------------------- Operator ---------------------------------*/
/*----------------------------------------------------------------------------*/

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		isSigned = other.isSigned;

	std::cout << "AForm Copy Assignment Operator called" << std::endl;
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const AForm &aForm)
{
	out << "Form: " << aForm.getName() << ", Signed: "
		<< (aForm.getSigned() ? "Yes" : "No")
		<< ", Sign Grade: " << aForm.getGradeToSign()
		<< ", Execute Grade: " << aForm.getGradeToExecute() << std::endl;

	return (out);
}

/*----------------------------------------------------------------------------*/
/*------------------------------ Member Functions ----------------------------*/
/*----------------------------------------------------------------------------*/

const std::string	&AForm::getName() const
{
	return (name);
}

bool	AForm::getSigned() const
{
	return (isSigned);
}

int	AForm::getGradeToSign() const
{
	return (signGrade);
}

int	AForm::getGradeToExecute() const
{
	return (executeGrade);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > signGrade)
		throw GradeTooLowException();

	isSigned = true;
}

void	AForm::requirements(const Bureaucrat &executor) const
{
	if (!this->isSigned)
		throw GradeNotSignedException();
	if (executor.getGrade() > executeGrade)
		throw GradeTooLowException();
}

/*----------------------------------------------------------------------------*/
/*--------------------------- Exception Definitions --------------------------*/
/*----------------------------------------------------------------------------*/

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("AForm grade is too High!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("AForm grade is too Low!");
}

const char *AForm::GradeNotSignedException::what() const throw()
{
	return ("AForm isn't signed!");
}

const char *AForm::FileNotOpenException::what() const throw()
{
	return ("File could not be opened.");
}
