/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/20 14:27:31 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"
#include <iostream>
#include <string>

Dog::Dog(void) : _type("Dog") {
    std::cout << "Dog Construcor Called" << std::endl;
}
Dog::Dog(const Dog &a) {
    *this = a;
}

Dog::~Dog(void) {
    std::cout << "Dog Destructor Called" << std::endl;  
}

Dog& Dog::operator=(const Dog &a) {
    if (this != &a) {
        this->_type = a._type;
    }
    return *this;
}

void Dog::makeSound (void) const{
    std::cout << "Woof, woof" << std::endl;
}

std::string Dog::getType (void) const {
    return this->_type;
}
