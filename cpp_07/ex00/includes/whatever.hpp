/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:32:24 by andre-da          #+#    #+#             */
/*   Updated: 2024/08/24 12:30:56 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include "libft.h"

template <typename value>
void	swap(value &a, value &b)
{
	value	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename value>
value	min(const value &a, const value &b)
{
	return ((a < b) ? a : b);
}

template <typename value>
value	max(const value &a, const value &b)
{
	return ((a > b) ? a : b);
}

#endif
