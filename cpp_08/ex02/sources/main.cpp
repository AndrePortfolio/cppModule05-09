/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:32:24 by andre-da          #+#    #+#             */
/*   Updated: 2024/09/23 17:18:43 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.hpp"

int main()
{
	std::cout << GREEN << "\nSUBJECT TEST + COMPARISONS" << RESET;
	mutantStackVersion();
	listVersion();
	vectorVersion();

	std::cout << GREEN << "\nITERATE INT ARRAY\n" << RESET;
	int arr[] = {10, 22, -33, 34, 25, 32};
	MutantStack<int> stackArray(arr, sizeof(arr) / sizeof(int));
	for (MutantStack<int>::iterator it = stackArray.begin(); it != stackArray.end(); ++it)
		std::cout << *it << " ";

	std::cout << GREEN << "\nITERATE CHAR ARRAY\n" << RESET;
	char arr2[] = {'a', 'z', '.', 'g', '<', '9', 'k', 'l', '-', 'D'};
	MutantStack<char> stackArray2(arr2, sizeof(arr2) / sizeof(char));
	for (MutantStack<char>::iterator it = stackArray2.begin(); it != stackArray2.end(); ++it)
		std::cout << *it << " ";

	std::cout << GREEN << "\nITERATE STRING ARRAY\n" << RESET;
	std::string arr3[] = {"here", "to", "code", "the", "universe"};
	MutantStack<std::string> stackArray3(arr3, sizeof(arr3) / sizeof(std::string));
	for (MutantStack<std::string>::iterator it = stackArray3.begin(); it != stackArray3.end(); ++it)
		std::cout << *it << " ";
	std::cout << GREEN << "\nITERATE STRING ARRAY" << RED << " - IN REVERSE\n" << RESET;
	for (MutantStack<std::string>::reverse_iterator it = stackArray3.rbegin(); it != stackArray3.rend(); ++it)
		std::cout << *it << " ";

	std::cout << "\n" << std::endl;
	return (0);
}
