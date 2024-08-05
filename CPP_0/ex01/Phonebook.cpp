/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:24:26 by aaronespino       #+#    #+#             */
/*   Updated: 2024/08/05 18:52:21 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"

// La estructura Clase::funcion() es un método
// Los metodos sirven para modificar o acceder a los atributos de una clase
// En este caso, isEmpty() devuelve el valor de la variable empty

PhoneBook::PhoneBook() : currentContact(0) {}

void PhoneBook::addContact() {
	if (currentContact < 8) {
		contacts[currentContact].setContact();
		currentContact++; 
	}
	else {
		currentContact = 0;
		contacts[currentContact].setContact();
		currentContact++;
	}
}

# include <iostream>

std::string add_s(int n) {
	std::string ret;

	while (n)
	{
		ret.append(" ");
		n--;
	}
	return (ret);
}

std::string fix_w(std::string str) {
	if (str.size() > 10)
	{
		str.resize(10);
		str[str.size() - 1] = '.';
	}
	return (str);
}

void PhoneBook::searchContact() {

	std::string str;
	char c = '0';
	int i = 0;

	std::cout << "|    Index |First Name| Last Name|  Nickname|" << std::endl;
	while (++c <= '8') {
		if (contacts[c - 1 - '0'].getFirstName().size() && ++i)
		{
			str = c;
			str = fix_w(str);
			std::cout << "|" << add_s(10 - str.size()) << str;
			str = fix_w(contacts[c - 1  - '0'].getFirstName());
			std::cout << "|" << add_s(10 - str.size()) << str;
			str = fix_w(contacts[c - 1 - '0'].getLastName());
			std::cout << "|" << add_s(10 - str.size()) << str;
			str = fix_w(contacts[c - 1 - '0'].getNickname());
			std::cout << "|" << add_s(10 - str.size()) << str;
			std::cout << "|" << std::endl;
		}
	}
	
	while (!std::cin.eof())
	{
		std::cout << "Enter index to display contact details: ";
		if (std::getline(std::cin, str) && str != "")
		{
			// if (str == "EXIT") {exit(1);}
			if ((str[0] < '1' || str[0] > '8') || str.length() != 1 || str == "") {std::cout << "Invalid index.\n";}
			else if (str[0] >= '1' && str[0] <= '8') {
				displayContact(atoi(str.c_str()));
				break;}
		}
	}
	if (std::cin.eof()) {
		std::cout << std::endl;
		exit(1);}
}

void PhoneBook::displayContact(int i) {
	if (contacts[i].isEmpty()) {
		std::cout << "No contact at this index.\n";
	}
	else
		contacts[i].showContact();
}
			
