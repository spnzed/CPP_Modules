/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/26 15:58:23 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"
#include <iostream>
#include <string>

Dog::Dog(void) : _type("Dog") {
    std::cout << "Dog construcor called" << std::endl;
    this->brain = new Brain;
}

Dog::Dog(const Dog &a) {
    std::cout << "Dog copy constructor called" << std::endl;
    this->brain = new Brain();
    *this = a;
}

Dog::~Dog(void) {
    std::cout << "Dog destructor called" << std::endl;    
    delete this->brain;
}

Dog& Dog::operator=(const Dog &a) {
    std::cout << "Dog copy assignment operator" << std::endl;
    if (this != &a) {
        this->_type = a._type;
        *this->brain = *a.brain;
    }
    return *this;
}

void Dog::makeSound (void) const{
    std::cout << "Woof, woof" << std::endl;
}

std::string Dog::getType (void) const {
    return this->_type;
}
