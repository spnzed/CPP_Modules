/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/19 13:03:37 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"
#include <iostream>
#include <string>

Cat::Cat(void) : _type("Cat_default") {
    std::cout << "Cat Construcor Called" << std::endl;
}

Cat::Cat(const Cat &a) {
    *this = a;
}

Cat::~Cat(void) {
    std::cout << "Cat Destructor Called" << std::endl;    
}

Cat& Cat::operator=(const Cat &a) {
    if (this != &a) {
        this->_type = a._type;
    }
    return *this;
}

void Cat::makeSound (void) const {
    std::cout << "Meow" << std::endl;
}

std::string Cat::getType (void) const {
    return this->_type;
}
