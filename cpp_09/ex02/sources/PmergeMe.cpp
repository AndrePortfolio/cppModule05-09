/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:19:02 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/09/26 17:54:33 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.hpp"

/*----------------------------------------------------------------------------*/
/*-------------------------- Constructors & Destructor -----------------------*/
/*----------------------------------------------------------------------------*/

PmergeMe::PmergeMe() : vec(), lst() {}

PmergeMe::PmergeMe(int argc, char* argv[])
{
	checkInput(argc, argv);
	printState("Before: ");
	sort();
	printState("After:  ");
	printSpeeds();
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	*this = copy;
}

PmergeMe::~PmergeMe() {}

/*----------------------------------------------------------------------------*/
/*--------------------------------- Operator ---------------------------------*/
/*----------------------------------------------------------------------------*/

PmergeMe&	PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->vec = other.vec;
		this->lst = other.lst;
	}
	return (*this);
}

/*----------------------------------------------------------------------------*/
/*------------------------------ Member Functions ----------------------------*/
/*----------------------------------------------------------------------------*/

void	PmergeMe::checkInput(int argc, char* argv[])
{
	if (argc < 2)
		throw std::invalid_argument("Usage: ./RPN <integerSequence>");

	for (int i = 1; i < argc; i++)
	{
		double value = std::stod(argv[i]);

		if (value <= 0)
			throw std::out_of_range("Error: input must be a positive integer");
		if (value > std::numeric_limits<int>::max())
			throw std::out_of_range("Error: input is too large");
		lst.push_back(static_cast<int>(value));
		vec.push_back(static_cast<int>(value));
	}
}

void	PmergeMe::vDivide(int start, int end)
{
	if (start == end)
		return ;

	int mid = start + (end - start) / 2;

	vDivide(start, mid);
	vDivide(mid + 1, end);
	vMerge(start, mid, end);
}

void	PmergeMe::lDivide(int start, int end)
{
	if (start == end)
		return ;

	int mid = start + (end - start) / 2;

	lDivide(start, mid);
	lDivide(mid + 1, end);
	lMerge(start, mid, end);
}

void	PmergeMe::vMerge(int start, int mid, int end)
{
	std::vector<int> left(vec.begin() + start, vec.begin() + mid + 1);
	std::vector<int> right(vec.begin() + mid + 1, vec.begin() + end + 1);

	size_t l = 0, r = 0, v = start;

	while (l < left.size() && r < right.size())
	{
		if (left[l] <= right[r])
			vec[v++] = left[l++];
		else
			vec[v++] = right[r++];
	}
	while (l < left.size())
		vec[v++] = left[l++];
	while (r < right.size())
		vec[v++] = right[r++];
}

void	PmergeMe::lMerge(int start, int mid, int end)
{
	std::list<int>	merged;
	lIterator		itLeft = std::next(lst.begin(), start);
	lIterator		itRight = std::next(lst.begin(), mid + 1);
	lIterator		endLeft = std::next(lst.begin(), mid + 1);
	lIterator		endRight = std::next(lst.begin(), end + 1);

	while (itLeft != endLeft && itRight != endRight)
	{
		if (*itLeft <= *itRight)
		{
			merged.push_back(*itLeft);
			itLeft++;
		}
		else
		{
			merged.push_back(*itRight);
			itRight++;
		}
	}
	while (itLeft != endLeft)
	{
		merged.push_back(*itLeft);
		itLeft++;
	}
	while (itRight != endRight)
	{
		merged.push_back(*itRight);
		itRight++;
	}
	lIterator	it = std::next(lst.begin(), start);

	it = lst.erase(it, std::next(it, end - start + 1));
	it = lst.insert(it, merged.begin(), merged.end());
}

void	PmergeMe::sort()
{
	int size;

	if (vec.size() != lst.size())
		throw std::runtime_error("Error: parsing input");
	else
		size = vec.size();

	if (size > 1)
	{
		std::clock_t start;
		std::clock_t end;

		start = std::clock();
		vDivide(0, size - 1);
		end = std::clock();
		vectorSpeed = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1e6;

		start = std::clock();
		lDivide(0, size - 1);
		end = std::clock();
		listSpeed = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1e6;
	}
}

void	PmergeMe::printState(const std::string& state) const
{
	std::cout << state;
	for (vConstIterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	// std::cout << "\n" << state;
	// for (lConstIterator it = lst.begin(); it != lst.end(); ++it)
	// 	std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::printSpeeds() const
{
	std::cout	<< "Time to process a range of " << vec.size()
					<< " elements with std::vector: "
					<< vectorSpeed << " us" << std::endl;
	std::cout	<< "Time to process a range of " << lst.size()
					<< " elements with std::list:   "
					<< listSpeed << " us" << std::endl;
}
