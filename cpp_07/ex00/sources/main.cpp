/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:32:24 by andre-da          #+#    #+#             */
/*   Updated: 2024/08/24 12:39:29 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int main(void)
{
	std::cout << GREEN << "\nTEST INTEGERS\n" << RESET;
	int	a = 2;
	int	b = 3;

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::cout << GREEN << "\nTEST STRINGS\n" << RESET;
	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

	std::cout << GREEN << "\nTEST DOUBLES\n" << RESET;
	double x = 3.14;
    double y = 2.71;

    ::swap(x, y);
    std::cout << "x = " << x << ", y = " << y << std::endl;
    std::cout << "min(x, y) = " << ::min(x, y) << std::endl;
    std::cout << "max(x, y) = " << ::max(x, y) << std::endl;

	std::cout << GREEN << "\nTEST CHARS\n" << RESET;
	char p = 'z';
    char q = 'a';

    ::swap(p, q);
    std::cout << "p = " << p << ", q = " << q << std::endl;
    std::cout << "min(p, q) = " << ::min(p, q) << std::endl;
    std::cout << "max(p, q) = " << ::max(p, q) << std::endl;

	std::cout << GREEN << "\nTEST BOOLS\n" << RESET;
	bool t = true;
    bool f = false;

    ::swap(t, f);
    std::cout << "t = " << t << ", f = " << f << std::endl;
    std::cout << "min(t, f) = " << ::min(t, f) << std::endl;
    std::cout << "max(t, f) = " << ::max(t, f) << std::endl;

	return (0);
}
