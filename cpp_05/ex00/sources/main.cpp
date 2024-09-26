/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:32:24 by andre-da          #+#    #+#             */
/*   Updated: 2024/08/20 11:37:08 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int main()
{
	try
	{
		Bureaucrat b1("b1", 1);

		std::cout << b1 << std::endl;
		b1.decrementGrade(25);
		std::cout << b1 << std::endl;
		b1.incrementGrade(10);
		std::cout << b1 << std::endl;

		Bureaucrat b2("b2", 75);

		std::cout << b2 << std::endl;
		b2.incrementGrade(75);
		// b2.decrementGrade(76);
		std::cout << b2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
