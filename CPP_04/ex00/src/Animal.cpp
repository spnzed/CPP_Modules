/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/30 18:32:57 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include <iostream>
#include <string>

Animal::Animal(void) : _type("Animal_default") {
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &a) {
    std::cout << "Animal copy constructor called" << std::endl;
    *this = a;
}

Animal::~Animal(void) {
    std::cout << "Animal destructor called" << std::endl;  
}

Animal& Animal::operator=(const Animal &a) {
    std::cout << "Animal copy assignment operator" << std::endl;
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
