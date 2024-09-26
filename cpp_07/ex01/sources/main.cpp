/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:32:24 by andre-da          #+#    #+#             */
/*   Updated: 2024/08/24 14:48:19 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int main(void)
{
	const int arraySize = 10;

	std::cout << GREEN << "\nINT ARRAY    -> " << RESET << "|";

	int	iArray[arraySize] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106};
	for (size_t i = 0; i < arraySize; i++)
	{
		if (iArray[i] != '\0')		
			std::cout << std::setw(5) << iArray[i] << "| ";
	}

	std::cout << YELLOW << "\nprint:          " << RESET << "|";
	iter(iArray, arraySize, print);
	std::cout << YELLOW << "\nconvertToChar:  " << RESET << "|";
	iter(iArray, arraySize, convertToChar);
	std::cout << YELLOW << "\nconvertToFloat: " << RESET << "|";
	iter(iArray, arraySize, convertToFloat);

	std::cout << GREEN << "\n\nCHAR ARRAY   -> " << RESET << "|";

	char	cArray[arraySize] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	for (size_t i = 0; i < arraySize; i++)
	{
		if (cArray[i] != '\0')
			std::cout << std::setw(5) << cArray[i] << "| ";
	}

	std::cout << YELLOW << "\nprint:          " << RESET << "|";
	iter(cArray, arraySize, print);
	std::cout << YELLOW << "\nconvertToInt:   " << RESET << "|";
	iter(cArray, arraySize, convertToInt);
	std::cout << YELLOW << "\nconvertToFloat: " << RESET << "|";
	iter(cArray, arraySize, convertToFloat);

	std::cout << GREEN << "\n\nFLOAT ARRAY ->  " << RESET << "|";

	float	fArray[arraySize] = {97.0f, 98.1f, 99.2f, 100.3f, 101.4f, 102.5f, 103.6f, 104.7f, 105.8f, 106.9f};
	for (size_t i = 0; i < arraySize; i++)
	{
		if (fArray[i] != '\0')
			std::cout << std::setw(5) << fArray[i] << "| ";
	}

	std::cout << YELLOW << "\nprint:          " << RESET << "|";
	iter(fArray, arraySize, print);
	std::cout << YELLOW << "\nconvertToInt:   " << RESET << "|";
	iter(fArray, arraySize, convertToInt);
	std::cout << YELLOW << "\nconvertToChar:  " << RESET << "|";
	iter(fArray, arraySize, convertToChar);

	std::cout << GREEN << "\n\nSTRING ARRAY -> " << RESET << "|";
	std::string	sArray[arraySize] = {"hey", "this", "is", "fun", "I", "love", "to", "make", "42", "tests"};
	for (size_t i = 0; i < arraySize; i++)
	{
		std::cout << std::setw(5) << sArray[i] << "| ";
	}
	std::cout << YELLOW << "\nprint:          " << RESET << "|";
	iter(sArray, arraySize, print);

	std::cout << "\n" << std::endl;
	return (0);
}
