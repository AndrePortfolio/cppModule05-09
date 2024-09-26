/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:27:25 by andre-da          #+#    #+#             */
/*   Updated: 2024/09/23 13:41:58 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.hpp"

int main()
{
	Span numbers = Span(100);	// test different values (increase nbr distribution for 1k+)

	numbers.fillContainer();

	std::cout << CYAN <<  "\nShortest span: " << RESET <<  numbers.shortestSpan() << std::endl;
	std::cout << CYAN <<  "Longest  span: " << RESET << numbers.longestSpan() << std::endl;

	// SIMPLE MAIN FROM SUBJECT
	// Span sp = Span(5);
	// sp.addNumber(6);
	// sp.addNumber(3);
	// sp.addNumber(17);
	// sp.addNumber(9);
	// sp.addNumber(11);
	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;
	return (0);
}
