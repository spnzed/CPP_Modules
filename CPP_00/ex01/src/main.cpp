/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:25:28 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/14 14:38:13 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"
#include <iostream>

int	main()
{
	PhoneBook	phonebook;
	std::string	str;

	std::cout << "Initializing PhoneBook..." << std::endl;
	while (str != "EXIT")
	{
		std::cout << "Enter a command: ADD, SEARCH or EXIT" << std::endl;
		std::getline(std::cin, str);
		if (str == "ADD") {
			phonebook.addContact();
		} 
		else if (str == "SEARCH") {
			phonebook.searchContact();
		}
		else if (std::cin.eof()) {
			std::cout << std::endl;
			break;
		}
		else if (str == "") {
			std::cout << "Empty command. Please enter ADD, SEARCH or EXIT.\n" << std::endl;
		}
		else if (str != "EXIT") {
			std::cout << "Unknown command. Please enter ADD, SEARCH or EXIT.\n" << std::endl;
		}
	}
	return (0);
}
