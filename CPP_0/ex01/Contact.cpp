/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:35:53 by aaronespino       #+#    #+#             */
/*   Updated: 2024/06/05 15:34:47 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

// La estructura Clase::funcion() es un método
// Los metodos sirven para modificar o acceder a los atributos de una clase
// En este caso, isEmpty() devuelve el valor de la variable empty

// std::cout imprime en la consola
// std::cin lee de la consola
// std::getline lee una línea de la consola y la guarda en una variable

Contact::Contact() {}

void	Contact::setContact() {
	std::cout << "Enter First Name: ";
	std::getline(std::cin, firstName);
	std::cout << "Enter Last Name: ";
	std::getline(std::cin, lastName);
	std::cout << "Enter Nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin, darkestSecret);
	empty = false;
}

void	Contact::showContact() {
	std::cout << "First Name: " << firstName << std::endl;
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
