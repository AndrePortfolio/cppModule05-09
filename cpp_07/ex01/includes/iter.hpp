/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:32:24 by andre-da          #+#    #+#             */
/*   Updated: 2024/08/24 13:22:14 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include "libft.h"

template<typename T>
void	iter(T array[], size_t length, void (*func)(T&))
{
	for (size_t i = 0; i < length; i++)
	{
		func(array[i]);
	}
}

template <typename T>
void	print(T element)
{
	std::cout << std::setw(5) << element << "| ";
}

template <typename T>
void	convertToInt(T element)
{
	std::cout << std::setw(5) << static_cast<int>(element) << "| ";
}

template <typename T>
void	convertToChar(T element)
{
	std::cout << std::setw(5) << static_cast<char>(element) << "| ";
}

template <typename T>
void	convertToFloat(T element)
{
	std::cout << std::setw(5) << std::fixed << std::setprecision(1) << static_cast<float>(element) << "| ";
}

#endif
