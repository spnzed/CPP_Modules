/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:24:26 by aaronespino       #+#    #+#             */
/*   Updated: 2024/06/05 15:29:12 by aaronespino      ###   ########.fr       */
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

void PhoneBook::searchContact() {
    std::cout << "Index | First Name | Last Name | Nickname";
    for (int i = 0; i < 8; i++) {
        if (contacts[i].isEmpty()) break;
        else
        {
            std::cout << i << " | " \
            << contacts[i].getFirstName() << " | " \
            << contacts[i].getLastName() << " | " \
            << contacts[i].getNickname() << "\n";
        }}
    int j;
    std::cout << "Enter index to display contact details: ";
    std::cin >> j;
    if (j >= 0 && j < 8) {
        displayContact(j);
    }
    else
        std::cout << "Invalid index.\n";
}

void PhoneBook::displayContact(int i) {
    if (contacts[i].isEmpty()) {
        std::cout << "No contact at this index.\n";
    }
    else
        contacts[i].showContact();
}
            
