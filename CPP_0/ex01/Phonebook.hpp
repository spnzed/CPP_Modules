/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:24:24 by aaronespino       #+#    #+#             */
/*   Updated: 2024/06/07 13:12:14 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

// Clase PhoneBook

// Una clase es un molde para crear objetos que comparten atributos y métodos
// En este caso, la clase PhoneBook tiene atributos y métodos para manejar una lista de contactos
    // Los atributos son un array de Contact y un entero que indica el contacto actual
    // Los métodos son las funciones que permiten modificar o acceder a los atributos
class PhoneBook {
    private:
        Contact contacts[8];
        int currentContact;

    public:
        PhoneBook();
        void    addContact();
        void    searchContact();
        void    displayContact(int i);

};

#endif