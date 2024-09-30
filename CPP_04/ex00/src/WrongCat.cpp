/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/30 18:32:57 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"
#include <iostream>
#include <string>

WrongCat::WrongCat(void) : _type("WrongCat") {
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &a) {
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = a;
}

WrongCat::~WrongCat(void) {
    std::cout << "WrongCat destructor called" << std::endl;    
}

WrongCat& WrongCat::operator=(const WrongCat &a) {
    std::cout << "WrongCat copy assignment operator" << std::endl;
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

