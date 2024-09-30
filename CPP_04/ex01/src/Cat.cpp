/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/30 18:32:57 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"
#include <iostream>
#include <string>

Cat::Cat(void) : _type("Cat") {
    std::cout << "Cat constructor called" << std::endl;
    this->brain = new Brain;
}

Cat::Cat(const Cat &a) {
    std::cout << "Cat copy constructor called" << std::endl;
    this->brain = new Brain();
    *this = a;
}

Cat::~Cat(void) {
    std::cout << "Cat destructor called" << std::endl;    
    delete this->brain;
}

Cat& Cat::operator=(const Cat &a) {
    std::cout << "Cat copy assignment operator" << std::endl;
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
