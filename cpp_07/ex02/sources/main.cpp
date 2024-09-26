/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:32:24 by andre-da          #+#    #+#             */
/*   Updated: 2024/09/19 18:27:05 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	main(void)
{
	try
	{
		const int	arraySize = 10;
		Array<int>	array(arraySize);

		std::cout << GREEN << "\nDIPLAY EMPTY ARRAY -> " << RESET;
		for (size_t i = 0; i < arraySize; i++)
		{
			std::cout << array.getData(i) << " ";
		}
		std::cout << "\nArray Size: " << array.size() << "\n";

		int index = 9;
		array.setData(35, index);
		std::cout	<< CYAN << "Get index " << index << " data -> "\
					<< RESET << array.getData(index) << "\n";

		Array<int>	copyArray(array);
		std::cout << GREEN << "\nCOPY BY CONTRUCTOR -> " << RESET;
		for (size_t i = 0; i < arraySize; i++)
		{
			std::cout << copyArray.getData(i) << " ";
		}
		std::cout << "\nArray Size: " << copyArray.size() << "\n";
		
		Array<int>	copyArray2 = array;
		std::cout << GREEN << "\nCOPY BY ASSIGMENT  -> " << RESET;
		for (size_t i = 0; i < arraySize; i++)
		{
			std::cout << copyArray2.getData(i) << " ";
		}
		std::cout << "\nArray Size: " << copyArray2.size() << "\n";

		// int invalidIndex1 = -1;
		// int invalidIndex2 = 11;
		
		// array.setData(35, invalidIndex1);
		// std::cout	<< CYAN << "Get index " << invalidIndex1 << " data -> "\
		// 			<< RESET << array.getData(invalidIndex1) << "\n";
		
		// array.setData(35, invalidIndex2);
		// std::cout	<< CYAN << "Get index " << invalidIndex2 << " data -> "\
		// 			<< RESET << array.getData(invalidIndex2) << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	return (0);
}
