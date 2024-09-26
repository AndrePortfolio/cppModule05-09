/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre-da <andre-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:32:24 by andre-da          #+#    #+#             */
/*   Updated: 2024/09/19 16:44:33 by andre-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include "libft.h"

template<typename T>
class Array
{
	private:
		T*				data;
		unsigned int	arraySize;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array &copy);
		~Array();

		Array&	operator=(const Array &other);
		T&		operator[](unsigned int index) const;
		
		unsigned int	size() const;
		T				getData(int index) const;
		void			setData(const T& info, int index);
};

#include "Array.tpp"
#endif
