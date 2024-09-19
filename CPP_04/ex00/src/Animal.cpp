/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/19 13:03:53 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include <iostream>
#include <string>

Animal::Animal(void) : _type("Animal_default") {
    std::cout << "Animal Construcor Called" << std::endl;
}

Animal::Animal(const Animal &a) {
    *this = a;
}

Animal::~Animal(void) {
    std::cout << "Animal Destructor Called" << std::endl;  
}

Animal& Animal::operator=(const Animal &a) {
    if (this != &a) {
        this->_type = a._type;
    }
    return *this;
}

void Animal::makeSound (void) const {
    std::cout << "ASDF IM AN ANIMAL PLEASE GIVE ME A SPECIE TO LIVE BY" << std::endl;
}

std::string Animal::getType(void) const {
    return this->_type;
}
