/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/12 11:28:09 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>
#include <string>

Cat::Cat(void) : _type("Cat_default") {
    std::cout << "Cat Construcor Called" << std::endl;
    this->brain = new Brain;
}

Cat::~Cat(void) {
    std::cout << "Cat Destructor Called" << std::endl;    
    delete this->brain;
}

void Cat::makeSound (void) const {
    std::cout << "Meow" << std::endl;
}

std::string Cat::getType (void) const {
    return this->_type;
}