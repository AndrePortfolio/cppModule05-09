/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:07:08 by andre-da          #+#    #+#             */
/*   Updated: 2024/09/19 18:19:45 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/libft.h"

/*----------------------------------------------------------------------------*/
/*------------------------- Constructors & Destructor -----------------------*/
/*----------------------------------------------------------------------------*/

template <typename T>
Array<T>::Array() : data(NULL), arraySize(0){}


template <typename T>
Array<T>::Array(unsigned int n) : arraySize(n)
{
	data = new T[arraySize]();
}

template <typename T>
Array<T>::Array(const Array &copy) : data(NULL)
{
	*this = copy;
}

template <typename T>
Array<T>::~Array()
{
    delete[] data;
}

/*----------------------------------------------------------------------------*/
/*-------------------------------- Operators ---------------------------------*/
/*----------------------------------------------------------------------------*/

template <typename T>
Array<T>&   Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
        delete[] data;
		arraySize = other.arraySize;
		data = new T[arraySize]();
		for (size_t i = 0; i < arraySize; i++)
			data[i] = other.data[i];
	}
	return (*this);
}

template <typename T>
T&  Array<T>::operator[](unsigned int index) const
{
	if (index < 0 || index >= (int)arraySize)
		throw std::out_of_range("Index out of bounds");
	return (data[index]);
}

/*----------------------------------------------------------------------------*/
/*------------------------------ Member Functions ----------------------------*/
/*----------------------------------------------------------------------------*/

template <typename T>
unsigned int	Array<T>::size() const
{
	return (arraySize);
}

template <typename T>
T	Array<T>::getData(int index) const
{
	if (index < 0 || index >= (int)arraySize)
		throw std::out_of_range("Index out of bounds");
	return (data[index]);
}

template <typename T>
void	Array<T>::setData(const T& info, int index)
{
	if (index < 0 || index >= (int)arraySize)
		throw std::out_of_range("Index out of bounds");

    data[index] = info;
	std::cout << CYAN << "\nSet index " << index << " to " << info << RESET << "\n"; 
}

/*----------------------------------------------------------------------------*/
/*--------------------------- Exception Definitions --------------------------*/
/*----------------------------------------------------------------------------*/