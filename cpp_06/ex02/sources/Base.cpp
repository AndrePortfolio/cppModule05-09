/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:32:24 by andre-da          #+#    #+#             */
/*   Updated: 2024/08/24 12:12:32 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*----------------------------------------------------------------------------*/
/*-------------------------------- Destructor --------------------------------*/
/*----------------------------------------------------------------------------*/

Base::~Base()
{
	std::cout << "Destructor called" << std::endl;
}

/*----------------------------------------------------------------------------*/
/*-------------------------------- Functions ---------------------------------*/
/*----------------------------------------------------------------------------*/

Base*	generate(void)
{
	srand(static_cast<unsigned>(time(0)));

	int random = rand() % 3;

	if (random == 0)
		return (new A());
	else if (random == 1)
		return (new B());
	else if (random == 2)
		return (new C());
	return (NULL);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
}

void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);

		std::cout << "A\n\n";
	}
	catch(std::exception &e) {}
	try
	{
		(void)dynamic_cast<B&>(p);

		std::cout << "B\n\n";
	}
	catch(std::exception &e) {}
	try
	{
		(void)dynamic_cast<C&>(p);

		std::cout << "C\n\n";
	}
	catch(std::exception &e) {}

}
