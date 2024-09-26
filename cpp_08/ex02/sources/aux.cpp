/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:48:00 by andrealbuqu       #+#    #+#             */
/*   Updated: 2024/09/23 17:03:30 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.hpp"

void	mutantStackVersion()
{
	std::cout << BLUE << "\nSTACK --> " << RESET;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << " ";
	mstack.pop();
	std::cout << mstack.size() << " ";
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::stack<int> s(mstack);
}

void	listVersion()
{
	std::cout << CYAN << "\nLIST ---> " << RESET;
	std::list<int> mlist;
	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << mlist.back() << " ";
	mlist.pop_back();
	std::cout << mlist.size() << " ";
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(0);
	std::list<int>::iterator it = mlist.begin();
	std::list<int>::iterator ite = mlist.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::list<int> s(mlist);
}

void	vectorVersion()
{
	std::cout << YELLOW << "\nVECTOR -> " << RESET;
	std::vector<int> mvector;
	mvector.push_back(5);
	mvector.push_back(17);
	std::cout << mvector.back() << " ";
	mvector.pop_back();
	std::cout << mvector.size() << " ";
	mvector.push_back(3);
	mvector.push_back(5);
	mvector.push_back(737);
	mvector.push_back(0);
	std::vector<int>::iterator it = mvector.begin();
	std::vector<int>::iterator ite = mvector.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::vector<int> s(mvector);
	std::cout << std::endl;
}
