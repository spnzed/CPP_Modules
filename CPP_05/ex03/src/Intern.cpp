/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:44:00 by aaespino          #+#    #+#             */
/*   Updated: 2024/10/04 14:20:03 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};                             // Inicialización del array estático

Intern::Intern( ) {
    std::cout << "Intern constructor called" << std::endl;
}
Intern::~Intern( ) {
    std::cout << "Intern destructor called" << std::endl;

}
Intern::Intern( const Intern& old ) {
    std::cout << "Intern copy constructor called" << std::endl;
	*this = old;
}
Intern& Intern::operator=( const Intern& ) {
    std::cout << "Intern assignment operator called" << std::endl;
	return (*this);	
}

int Intern::getForm(std::string form) const {
    for (int i = 0; i < 3; i++) {
        if (forms[i] == form)
            return i;
    }
    return -1;
}

AForm*   Intern::makeForm(std::string form, std::string target) const {

    AForm *ret;

    switch (getForm(form)) {
        case 0: {
            ret = new ShrubberyCreationForm(target);
            std::cout << "Intern creates " << ret->getName();
            break ;
        }
        case 1: {
            ret = new RobotomyRequestForm(target);
            std::cout << "Intern creates " << ret->getName();
            break ;
        }
        case 2: {
            ret = new PresidentialPardonForm(target);
            std::cout << "Intern creates " << ret->getName();
            break ;
        }
        default: {
            std::cout << "Error: The introduced Form is not an available option" << std::endl;
            return (NULL);
        }
    }
    return ret;
}
