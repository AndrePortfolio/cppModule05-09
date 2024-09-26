/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:32:24 by andre-da          #+#    #+#             */
/*   Updated: 2024/08/21 12:49:47 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "libft.h"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			signGrade;
		const int			executeGrade;

	public:
		AForm();
		AForm(std::string name, int signGrade, int executeGrade);
		AForm(const AForm &copy);
		AForm& operator=(const AForm &other);
		virtual ~AForm();

		const std::string	&getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		void				beSigned(const Bureaucrat &bureaucrat);
		virtual void		execute(Bureaucrat const &executor) const = 0;
		void				requirements(const Bureaucrat &executor) const;

		class GradeTooHighException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class GradeNotSignedException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class FileNotOpenException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &aForm);

#endif
