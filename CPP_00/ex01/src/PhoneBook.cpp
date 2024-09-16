/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:24:26 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/14 14:37:28 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"
#include "../inc/Contact.hpp"
#include "../inc/utils.hpp"
#include <iostream>
#include <cstdlib>
#include <sstream>


// La estructura Clase::funcion() es un método
// Los metodos sirven para modificar o acceder a los atributos de una clase
// En este caso, isEmpty() devuelve el valor de la variable empty

PhoneBook::PhoneBook() : currentContact(0) {
}

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

void PhoneBook::searchContact() {

	std::string str;
	int i = 0;

	if (contacts[0].isEmpty()) {	
		std::cout << "PhoneBook is empty. Please ADD contacts." << std::endl;
	} else {

		std::cout << "|    Index |First Name| Last Name|  Nickname|" << std::endl;
		while (i < 8) {
			if (!contacts[i].isEmpty())
			{
				str = i + '1';
				str = fix_w(str);
				std::cout << "|" << add_s(10 - str.size()) << str;
				str = fix_w(contacts[i].getFirstName());
				std::cout << "|" << add_s(10 - str.size()) << str;
				str = fix_w(contacts[i].getLastName());
				std::cout << "|" << add_s(10 - str.size()) << str;
				str = fix_w(contacts[i].getNickname());
				std::cout << "|" << add_s(10 - str.size()) << str;
				std::cout << "|" << std::endl;
			}
			i++;
		}
		
		while (!std::cin.eof()) {
        	std::cout << "Enter index to display contact details: ";
        	if (std::getline(std::cin, str) && !str.empty()) {
            	if (str.length() != 1 || str[0] < '1' || str[0] > '8') {
                	std::cout << "Invalid index.\n";
            	} else {
                	std::istringstream iss(str);
                	int index;
                	iss >> index; // Convertimos
                	if (iss.fail() || index < 1 || index > 8) {
                    	std::cout << "Invalid index.\n"; // Verifica si la conversión fue exitosa
                	} else {
                    	displayContact(index - 1); // Llama a displayContact con el índice
                    	break; // Salir del bucle si la conversión es exitosa
                }
            }
        }
    }
		if (std::cin.eof()) {
			std::cout << std::endl;
			exit(1);
		}
	}
}

void PhoneBook::displayContact(int i) {
	if (contacts[i].isEmpty()) {
		std::cout << "No contact at this index.\n";
	}
	else
		contacts[i].showContact();
}
			
