/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:09:03 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/17 16:14:45 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
#include <iostream>
#include <math.h>

Fixed::Fixed (void) : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed (const int& a) : _value(round(a * 256)) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed (const float& a) : _value(round(a * 256.0f)) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed (const Fixed& a) {
    std::cout << "Copy constructor called" << std::endl;
    *this = a;
}

Fixed &Fixed::operator=(const Fixed& a) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &a)
        this->setRawBits (a.getRawBits());
    return *this;
}

Fixed::~Fixed (void) {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits (void) const {
    return this->_value;
}

void Fixed::setRawBits (int const raw) {
    this->_value = raw;
}

float Fixed::toFloat( void ) const {
    return this->getRawBits() / 256.0f;
}

int Fixed::toInt( void ) const {
    return this->getRawBits() / 256;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    os << obj.toFloat();
    return os;
}
