/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:32:24 by andre-da          #+#    #+#             */
/*   Updated: 2024/08/21 18:00:30 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "libft.h"

class AForm;

class Intern
{
	private:
		static std::string	validNames[3];
		static AForm*		(*formConstructors[3])(const std::string &target);

	public:
		Intern();
		Intern(const Intern &copy);
		Intern& operator=(const Intern &other);
		~Intern();

		AForm	*makeForm(const std::string &formName, const std::string &target);

		class FormNotFoundException : public std::exception
		{
			const char	*what() const throw();
		};
};

#endif
