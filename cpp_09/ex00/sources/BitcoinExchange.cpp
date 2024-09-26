/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:32:24 by andre-da          #+#    #+#             */
/*   Updated: 2024/09/25 15:12:31 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.hpp"

/*----------------------------------------------------------------------------*/
/*-------------------------- Constructors & Destructor -----------------------*/
/*----------------------------------------------------------------------------*/

BitcoinExchange::BitcoinExchange() {
	readData();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
	*this = copy;
}

BitcoinExchange::~BitcoinExchange() {}

/*----------------------------------------------------------------------------*/
/*--------------------------------- Operator ---------------------------------*/
/*----------------------------------------------------------------------------*/

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		this->data = other.data;
	}
	return (*this);
}

/*----------------------------------------------------------------------------*/
/*------------------------------ Member Functions ----------------------------*/
/*----------------------------------------------------------------------------*/

void	BitcoinExchange::getData()
{
	for (constIterator it = data.begin(); it != data.end(); ++it)
	{
		std::cout << "Date: " << it->first << ", Rate: " << it->second << "\n";
	}
}

void	BitcoinExchange::readData()
{
	std::ifstream	file("data.csv");
	std::string		line;

	if (!file.is_open())
		throw std::runtime_error("Error: could not open \"data.csv\" file");
	std::getline(file, line);
	if (line != "date,exchange_rate")
		throw std::runtime_error("Error: invalid database");

	while (std::getline(file, line))
	{
		std::istringstream	iss(line);
		std::string			date;
		double				rate;

		std::getline(iss, date, ',');
		iss >> rate;
		data[date] = rate;
	}
}

static bool	errorHandling(std::istringstream& iss, double& quantity,
					const std::string& date, const std::string& line)
{
	std::istringstream	dateStream(date);
	double				year, month, day;
	char				del1, del2;

	if (!(dateStream >> year >> del1 >> month >> del2 >> day)
		|| del1 != '-' || del2 != '-' || !(iss >> quantity)
		|| year < 2009 || year > 2022 || month > 12
		|| month < 1 || day > 31 || day < 1)
	{
		std::cerr << "Error: bad input => " << line << "\n";
		return (true);
	}
	else if (quantity > 1000)
	{
		std::cerr << "Error: too large a number.\n";
		return (true);
	}
	else if (quantity < 0)
	{
		std::cerr << "Error: not a positive number.\n";
		return (true);
	}
	return (false);
}

void	BitcoinExchange::execute(char argv[])
{
	std::ifstream	file(argv);
	std::string		line;

	if (!file.is_open())
		throw std::runtime_error("Error: could not open file");
	if (file.peek() == std::ifstream::traits_type::eof())
		throw std::runtime_error("Error: empty file");

	std::getline(file, line);
	if (line != "date | value")
		throw std::runtime_error("Error: invalid file format");

	while (std::getline(file, line))
	{
		std::string			date;
		std::istringstream	iss(line);
		double				quantity;

		std::getline(iss, date, '|');
		constIterator it = data.lower_bound(date);

		if (errorHandling(iss, quantity, date, line))
			continue ;
		if (it == data.end() || (it != data.begin() && it->first != date))
			--it;
		if (it != data.end())
			std::cout << date << "=> " << quantity << " = " << it->second * quantity << "\n";
	}
}
