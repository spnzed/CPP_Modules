/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:30:50 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/25 11:14:29 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"

AMateria::AMateria(void): _type("Default_Materia") {
    std::cout << "\033[31m" << "[AMateria]\t\t" << "\033[0;4m" << "default constructor called" << "\033[0m" << std::endl;
}

AMateria::AMateria(const AMateria &a) {
    *this = a;
    std::cout << "\033[31m" << "[AMateria" << a.getName() << "]\t\t" << "\033[0;4m" << "copy constructor called" << "\033[0m" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type) {
    std::cout << "\033[31m" << "[AMateria" << type << "]\t\t" << "\033[0;4m" << "parameterized constructor called" << "\033[0m" << std::endl;
}

AMateria::~AMateria(void) {
    std::cout << "\033[31m" << "[AMateria]\t\t" << "\033[0;4m" << "destructor called" << "\033[0m" << std::endl;
}

AMateria& AMateria::operator=(const AMateria &a) {
    if (this != &a) {
        this->_type = a._type;
    }
    std::cout << "\033[31m" << "[AMateria]\t\t" << "\033[0;4m" << "assignment operator called" << "\033[0m" << std::endl;
    return *this;
}

std::string const & AMateria::getName(void) const {
    return this->_type;
}

void AMateria::use(ICharacter& target) {
    (void)target;
}
