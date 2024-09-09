/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:25:28 by aaronespino       #+#    #+#             */
/*   Updated: 2024/08/05 18:59:03 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>

int	main()
{
	PhoneBook	phonebook;
	std::string	str;

	while (str != "EXIT")
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, str);
		if (str == "ADD") {phonebook.addContact();} 
		else if (str == "SEARCH") {phonebook.searchContact();}
		else if (std::cin.eof()) {
			std::cout << std::endl;
			break;}
		else if (str == "") {}
		else {std::cout << "Unknown command. Please enter ADD, SEARCH or EXIT.\n";}
	}
	return (0);
}
