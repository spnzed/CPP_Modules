/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:31:09 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/25 11:14:29 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"

Cure::Cure(void) {
    this->AMateria::_type = "cure";
    std::cout << "\033[35;4m" << "[Cure]\t\t\t" << "\033[0;4m" << "default constructor called" << "\033[0m" << std::endl;
}

Cure::Cure(const Cure &a) {
    *this = a;
    std::cout << "\033[35;4m" << "[Cure]\t\t\t" << "\033[0;4m" << "copy constructor called" << "\033[0m" << std::endl;
}

Cure::~Cure(void) {
    std::cout << "\033[35;4m" << "[Cure]\t\t\t" << "\033[0;4m" << "destructor called" << "\033[0m" << std::endl;
}

Cure &Cure::operator=(const Cure &a) {
    if (this != &a) {
        this->_type = a._type;
    }
    std::cout << "\033[35;4m" << "[Cure]\t\t\t" << "\033[0;4m" << "assignment operator called" << "\033[0m" << std::endl;
    return *this;
}

AMateria* Cure::clone(void) const {
    return (new Cure(*this));
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

