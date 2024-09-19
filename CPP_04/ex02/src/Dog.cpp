/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/19 13:06:30 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"
#include <iostream>
#include <string>

Dog::Dog(void) : _type("Dog_default") {
    std::cout << "Dog Construcor Called" << std::endl;
    this->brain = new Brain;
}

Dog::Dog(const Dog &a) {
    *this = a;
}

Dog::~Dog(void) {
    std::cout << "Dog Destructor Called" << std::endl;    
    delete this->brain;
}

Dog& Dog::operator=(const Dog &a) {
    if (this != &a) {
        this->_type = a._type;
        this->brain = a.brain;
    }
    return *this;
}

void Dog::makeSound (void) const{
    std::cout << "Woof, woof" << std::endl;
}

std::string Dog::getType (void) const {
    return this->_type;
}