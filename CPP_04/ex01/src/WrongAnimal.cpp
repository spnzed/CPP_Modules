/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/20 13:22:37 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"
#include <iostream>
#include <string>

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal") {
    std::cout << "WrongAnimal Construcor Called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &a) {
    *this = a;
}

WrongAnimal::~WrongAnimal(void) {
    std::cout << "WrongAnimal Destructor Called" << std::endl;  
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &a) {
    if (this != &a) {
        this->_type = a._type;
    }
    return *this;
}

void WrongAnimal::makeSound (void) const {
    std::cout << "ASDF IM AN WRONGANIMAL PLEASE GIVE ME A SPECIE TO LIVE BY" << std::endl;
}

std::string WrongAnimal::getType(void) const {
    return this->_type;
}
