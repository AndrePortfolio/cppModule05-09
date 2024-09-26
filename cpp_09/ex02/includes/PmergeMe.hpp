/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:32:24 by andre-da          #+#    #+#             */
/*   Updated: 2024/09/26 15:50:56 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include "headers.hpp"

class PmergeMe
{
	private:
		std::vector<int>	vec;
		std::list<int>		lst;
		double				vectorSpeed;
		double				listSpeed;

		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe&	operator=(const PmergeMe &other);

		void	checkInput(int argc, char* argv[]);
		void	sort();
		void	vDivide(int start, int end);
		void	lDivide(int start, int end);
		void	vMerge(int start, int mid, int end);
		void	lMerge(int start, int mid, int end);
		void	printState(const std::string& state) const;
		void	printSpeeds() const;

	public:
		PmergeMe(int argc, char* argv[]);
		~PmergeMe();
};

typedef std::vector<int>::const_iterator	vConstIterator;
typedef std::vector<int>::iterator			vIterator;
typedef std::list<int>::const_iterator		lConstIterator;
typedef std::list<int>::iterator			lIterator;

#endif
