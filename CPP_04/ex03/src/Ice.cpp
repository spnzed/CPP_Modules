/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:31:21 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/25 11:14:29 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ice.hpp"

Ice::Ice(void) {
    this->AMateria::_type = "ice";
    std::cout << "\033[34;4m" << "[Ice]\t\t\t" << "\033[0;4m" << "default constructor called" << "\033[0m" << std::endl;
}

Ice::Ice(const Ice &a) {
    *this = a;
    std::cout << "\033[34;4m" << "[Ice]\t\t\t" << "\033[0;4m" << "copy constructor called" << "\033[0m" << std::endl;
}

Ice::~Ice(void) {
    std::cout << "\033[34;4m" << "[Ice]\t\t\t" << "\033[0;4m" << "destructor called" << "\033[0m" << std::endl;
}

Ice &Ice::operator=(const Ice &a) {
    if (this != &a) {
        this->_type = a._type;
    }
    std::cout << "\033[34;4m" << "[Ice]\t\t\t" << "\033[0;4m" << "assignment operator called" << "\033[0m" << std::endl;
    return *this;
}


AMateria* Ice::clone(void) const {
    return (new Ice(*this));
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
