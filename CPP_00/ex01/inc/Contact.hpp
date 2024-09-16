/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:24:31 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/13 15:48:16 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

// Clase Contact

// Una clase es un molde para crear objetos que comparten atributos y métodos
// En este caso, la clase Contact tiene atributos y métodos para manejar contactos
    // Los atributos son los datos de un contacto y un booleano que indica si el contacto está vacío
    // Los métodos son las funciones que permiten modificar o acceder a los atributos
class Contact {
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;
        bool        empty;

    public:
        Contact();
        void        setContact();
        void        showContact();
        bool        isEmpty();

        std::string getFirstName();
        std::string getLastName();
        std::string getNickname();
};

#endif
