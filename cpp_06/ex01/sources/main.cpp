/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrealbuquerque <andrealbuquerque@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:32:24 by andre-da          #+#    #+#             */
/*   Updated: 2024/08/24 10:53:45 by andrealbuqu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int main(void)
{
	Data	data;

	data.age = 24;
	data.contact = 917383917;
	data.name = "John";
	data.profession = "Firefighter";

	std::cout << CYAN << "\nORIGINAL DATA\n" << RESET
		<< "Age: " << data.age << "\n"
		<< "Contact: " << data.contact << "\n"
		<< "Name: " << data.name << "\n"
		<< "Profession: " << data.profession << "\n";

	uintptr_t	raw;

	raw = Serializer::serialize(&data);

	Data	*deserializedData;

	deserializedData = Serializer::deserialize(raw);

	std::cout << GREEN << "\nDESERIALIZED DATA\n" << RESET
		<< "Age: " << deserializedData->age << "\n"
		<< "Contact: " << deserializedData->contact << "\n"
		<< "Name: " << deserializedData->name << "\n"
		<< "Profession: " << deserializedData->profession << "\n\n";

	return (0);
}
