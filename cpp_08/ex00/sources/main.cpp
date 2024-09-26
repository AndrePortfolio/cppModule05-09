/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:32:24 by andre-da          #+#    #+#             */
/*   Updated: 2024/09/23 11:12:51 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.hpp"

int	main(void)
{
	int arr[] = {1, 2, 3, 4, 5};
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
	std::cout << GREEN << "\nVECTOR CONTAINER -> " << RESET;
	for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++)
		std::cout << arr[i] << " ";
	try
	{
		int	searchValue = 3;
		std::cout << "\nSearch value: " << searchValue << "\n";
		std::cout << "Found  value: " << easyfind(vec, searchValue) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << GREEN << "\nLIST CONTAINER ---> " << RESET;
	int arr2[] = {10, 20, 30, 40, 50};
	std::list<int> lst(arr2, arr2 + sizeof(arr2) / sizeof(int));
	for (size_t i = 0; i < sizeof(arr2) / sizeof(int); i++)
		std::cout << arr2[i] << " ";
	try
	{
		int	searchValue = 30;
		std::cout << "\nSearch value: " << searchValue << "\n";
		std::cout << "Found  value: " << easyfind(lst, searchValue) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << GREEN << "\nDEQUE CONTAINER --> " << RESET;
	int arr3[] = {100, 200, 300, 400, 500};
	std::deque<int> dque(arr3, arr3 + sizeof(arr3) / sizeof(int));
	for (size_t i = 0; i < sizeof(arr3) / sizeof(int); i++)
		std::cout << arr3[i] << " ";
	try
	{
		int	searchValue = 299;
		std::cout << "\nSearch value: " << searchValue << "\n";
		std::cout << "Found  value: " << easyfind(lst, searchValue) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}
