/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:32:24 by andre-da          #+#    #+#             */
/*   Updated: 2024/08/24 12:14:21 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int main(void)
{
	Base*	basePtr = generate();

	std::cout << CYAN << "\nIdentifying by pointer:   " << RESET;
	identify(basePtr);
	
	std::cout << GREEN << "Identifying by reference: " << RESET;
	identify(*basePtr);

	delete (basePtr);
	return (0);
}
