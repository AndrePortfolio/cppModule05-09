/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:32:24 by andre-da          #+#    #+#             */
/*   Updated: 2024/09/25 15:02:20 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.hpp"

static void	errorMessage(std::string message)
{
	std::cerr << RED << message << RESET << std::endl;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
		return (errorMessage("Usage: ./RPN <mathematicalExpression>"), 1);
	try
	{
		RPN	rpn;

		rpn.handleExpression(argv[1]);
		if (rpn.size() != 1)
			throw std::runtime_error("Error");
		std::cout << rpn.pop() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
