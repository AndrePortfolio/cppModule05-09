/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:32:24 by andre-da          #+#    #+#             */
/*   Updated: 2024/09/25 14:59:14 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include "headers.hpp"

class RPN
{
	private:
		std::stack<float>	stack;

		RPN(const RPN &copy);
		RPN&	operator=(const RPN &other);

		void	performOperation(std::string& token);

	public:
		RPN();
		~RPN();

		void	push(float value);
		float	pop();
		void	handleExpression(char* argv);
		int		size();
};

#endif
