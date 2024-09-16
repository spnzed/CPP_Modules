/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:09:03 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/16 15:03:39 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed (void) : _value(0) {
    std::cout << "Default constructor called" << std::endl;
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
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits (int const raw) {
    this->_value = raw;
}
