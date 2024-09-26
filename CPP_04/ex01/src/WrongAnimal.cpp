/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/26 15:42:39 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"
#include <iostream>
#include <string>

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal") {
    std::cout << "WrongAnimal construcor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &a) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = a;
}

WrongAnimal::~WrongAnimal(void) {
    std::cout << "WrongAnimal destructor called" << std::endl;  
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &a) {
    std::cout << "WrongAnimal copy assignment operator" << std::endl;
    if (this != &a) {
        this->_type = a._type;
    }
    return *this;
}

void WrongAnimal::makeSound (void) const {
    std::cout << "ASDF IM A WRONGANIMAL PLEASE GIVE ME A SPECIE TO LIVE BY" << std::endl;
}

std::string WrongAnimal::getType(void) const {
    return this->_type;
}
