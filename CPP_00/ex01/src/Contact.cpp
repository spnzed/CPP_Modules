/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:35:53 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/14 14:26:44 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"
#include <iostream>
#include <cstdlib>

// La estructura Clase::funcion() es un método
// Los metodos sirven para modificar o acceder a los atributos de una clase
// En este caso, isEmpty() devuelve el valor de la variable empty

// std::cout imprime en la consola
// std::cin lee de la consola
// std::getline lee una línea de la consola y la guarda en una variable

Contact::Contact() : empty(true) {}

void	Contact::setContact() {

	while (1) {
		std::cout << "Enter First Name: ";
		std::getline(std::cin, firstName);
		if (std::cin.eof()) {
			std::cout << std::endl;
			exit (1);
		}
		else if (firstName == "") {
			std::cout << "Invalid input. Empty line is not permited" << std::endl;
		} else {
			break;
		}
	}

	while (1) {
		std::cout << "Enter Last Name: ";
		std::getline(std::cin, lastName);
		if (std::cin.eof()) {
			std::cout << std::endl;
			exit (1);
		}
		else if (lastName == "") {
			std::cout << "Invalid input. Empty line is not permited" << std::endl;
		} else {
			break;
		}
	}

	while (1) {
		std::cout << "Enter Nickname: ";
		std::getline(std::cin, nickname);
		if (std::cin.eof()) {
			std::cout << std::endl;
			exit (1);
		}
		else if (nickname == "") {
			std::cout << "Invalid input. Empty line is not permited" << std::endl;
		} else {
			break;
		}
	}

	while (1)
	{
		bool isValid = true;

		std::cout << "Enter Phone Number: ";
		std::getline(std::cin, phoneNumber);
		if (std::cin.eof()) {
			std::cout << std::endl;
			exit (1);
		}
		for (unsigned long i = 0; i < phoneNumber.length(); ++i) {
			if (phoneNumber[i] < '0' || phoneNumber[i] > '9') {
				isValid = false;
			}
		}
		if (phoneNumber == "") {
			std::cout << "Invalid input. Empty line is not permited" << std::endl;
		}
		else if (isValid) {
			break;	
		} else {
			std::cout << "Invalid input. Please enter numbers only." << std::endl;
		}
	}

	while (1) {
		std::cout << "Enter Darkest Secret: ";
		std::getline(std::cin, darkestSecret);
		if (std::cin.eof()) {
			std::cout << std::endl;
			exit (1);
		}
		else if (darkestSecret == "") {
			std::cout << "Invalid input. Empty line is not permited" << std::endl;
		} else {
			break;
		}
	}
	empty = false;
}

void	Contact::showContact() {
	std::cout << "First Name: " << getFirstName() << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

bool	Contact::isEmpty() {
	return empty;
}

// Getters: métodos que devuelven el valor de un atributo
// std::string es una clase que representa un string
std::string	Contact::getFirstName() {
	return firstName;
}

std::string	Contact::getLastName() {
	return lastName;
}

std::string	Contact::getNickname() {
	return nickname;
}
