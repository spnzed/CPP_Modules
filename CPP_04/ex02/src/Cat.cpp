/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/20 14:21:48 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"
#include <iostream>
#include <string>

Cat::Cat(void) : _type("Cat_default") {
    std::cout << "Cat Construcor Called" << std::endl;
    this->brain = new Brain;
}

Cat::Cat(const Cat &a) {
    this->brain = new Brain();
    *this = a;
}

Cat::~Cat(void) {
    std::cout << "Cat Destructor Called" << std::endl;    
    delete this->brain;
}

Cat& Cat::operator=(const Cat &a) {
    if (this != &a) {
        this->_type = a._type;
        *this->brain = *a.brain;
    }
    return *this;
}

void Cat::makeSound (void) const {
    std::cout << "Meow" << std::endl;
}

std::string Cat::getType (void) const {
    return this->_type;
}
