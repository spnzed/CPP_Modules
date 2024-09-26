/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/26 15:42:39 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"
#include <iostream>
#include <string>

Dog::Dog(void) : _type("Dog") {
    std::cout << "Dog construcor called" << std::endl;
}
Dog::Dog(const Dog &a) {
    std::cout << "Dog copy constructor called" << std::endl;
    *this = a;
}

Dog::~Dog(void) {
    std::cout << "Dog destructor called" << std::endl;  
}

Dog& Dog::operator=(const Dog &a) {
    std::cout << "Dog copy assignment operator" << std::endl;
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
