/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/12 11:27:52 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>
#include <string>

Animal::Animal(void) : _type("Animal_default") {
    std::cout << "Animal Construcor Called" << std::endl;
}

Animal::~Animal(void) {
    std::cout << "Animal Destructor Called" << std::endl;
}

void Animal::makeSound (void) const {
    std::cout << "ASDF IM AN ANIMAL PLEASE GIVE ME A SPECIE TO LIVE BY" << std::endl;
}

std::string Animal::getType(void) const {
    return this->_type;
}
