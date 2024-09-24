/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/20 13:22:31 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"
#include <iostream>
#include <string>

WrongCat::WrongCat(void) : _type("WrongCat") {
    std::cout << "WrongCat Construcor Called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &a) {
    *this = a;
}

WrongCat::~WrongCat(void) {
    std::cout << "WrongCat Destructor Called" << std::endl;    
}

WrongCat& WrongCat::operator=(const WrongCat &a) {
    if (this != &a) {
        this->_type = a._type;
    }
    return *this;
}

void WrongCat::makeSound (void) const {
    std::cout << "Meow" << std::endl;
}

std::string WrongCat::getType (void) const {
    return this->_type;
}

