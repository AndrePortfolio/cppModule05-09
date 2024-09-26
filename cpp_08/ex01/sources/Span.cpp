/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:32:24 by andre-da          #+#    #+#             */
/*   Updated: 2024/09/23 15:50:32 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.hpp"

/*----------------------------------------------------------------------------*/
/*------------------------- Constructors & Destructor ------------------------*/
/*----------------------------------------------------------------------------*/

Span::Span(){}

Span::Span(unsigned int N) : maxSize(N){}

Span::Span(const Span &copy)
{
	*this = copy;
}

Span::~Span(){}

/*----------------------------------------------------------------------------*/
/*--------------------------------- Operator ---------------------------------*/
/*----------------------------------------------------------------------------*/

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->maxSize = other.maxSize;
		this->numbers = other.numbers;
	}
	return (*this);
}

/*----------------------------------------------------------------------------*/
/*------------------------------ Member Functions ----------------------------*/
/*----------------------------------------------------------------------------*/

void	Span::fillContainer()
{
	if (numbers.size() >= maxSize)
		throw std::runtime_error("Container is already full");
	else
	{
		std::random_device				rd;				// creates a seed for random numbers
		std::mt19937					gen(rd());		// Mersenne Twister algorithm
		std::uniform_int_distribution<>	dis(1, 1000);

		while (numbers.size() < maxSize)
			addNumber(dis(gen));
	}

	std::sort(numbers.begin(), numbers.end());
	std::cout << GREEN << "CONTAINER -> " << RESET;

	for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
		std::cout << *it << " ";

	std::cout << std::endl;
}

void	Span::addNumber(int number)
{
	if (numbers.size() < maxSize)
		numbers.push_back(number);
	else
		throw std::runtime_error("Can't add any more numbers");
}

void	Span::prepareSpan()
{
	if (numbers.size() <= 1)
		throw std::runtime_error("Not enought numbers");
	std::sort(numbers.begin(), numbers.end());
}

size_t	Span::shortestSpan()
{
	prepareSpan();

	size_t	shortSpan = std::numeric_limits<size_t>::max();
	int		i = 0, index = 0;

	for (std::vector<int>::iterator it = numbers.begin(); it != std::prev(numbers.end()); ++it)
	{
		size_t	diff = *std::next(it) - *it;
		if (diff < shortSpan)
		{
			shortSpan = diff;
			index = i;
		}
		i++;
	}
	std::cout << index << " <-> " << index + 1 << CYAN <<  " diff: " << RESET;
	return (shortSpan);
}

size_t	Span::longestSpan()
{
	prepareSpan();

	return (numbers.back() - numbers.front());
}
