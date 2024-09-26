/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:27:31 by andre-da          #+#    #+#             */
/*   Updated: 2024/09/23 13:36:04 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include "headers.hpp"

class Span
{
	private:
		unsigned int		maxSize;
		std::vector<int>	numbers;

		Span();

	public:
		Span(unsigned int N);
		Span(const Span &copy);
		Span& operator=(const Span &other);
		~Span();

		void	fillContainer();
		void	addNumber(int number);
		void	prepareSpan();
		size_t	shortestSpan();
		size_t	longestSpan();
};

#endif
