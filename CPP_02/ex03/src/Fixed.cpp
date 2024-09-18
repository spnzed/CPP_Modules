/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:09:03 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/18 19:09:52 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"
#include <iostream>
#include <cmath>

// CONSTRUCTORS

Fixed::Fixed (void) : _value(0) {
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed (const Fixed& a) {
    // std::cout << "Copy constructor called" << std::endl;
    *this = a;
}

Fixed::~Fixed (void) {
    // std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed (const int& a) : _value(roundf(a * 256)) {
    // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed (const float& a) : _value(roundf(a * 256.0f)) {
    // std::cout << "Float constructor called" << std::endl;
}

// ARITHMETIC OPERATORS

Fixed	Fixed::operator+(const Fixed& copy) const {
    return(this->toFloat() + copy.toFloat());
}

Fixed	Fixed::operator-(const Fixed& copy) const {
    return(this->toFloat() - copy.toFloat());

}

Fixed	Fixed::operator*(const Fixed& copy) const {
    return(this->toFloat() * copy.toFloat());
}

Fixed	Fixed::operator/(const Fixed& copy) const {
    return(this->toFloat() / copy.toFloat());
}

Fixed &Fixed::operator=(const Fixed& a) {
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &a) {
        this->setRawBits (a.getRawBits());
    }
    return *this;
}

// COMPARISON OPERATORS

int Fixed::operator>(const Fixed& a) {
    if (this->getRawBits() > a.getRawBits())
        return 1;
    return 0;
}

int Fixed::operator<(const Fixed& a) {
    if (this->getRawBits() < a.getRawBits())
        return 1;
    return 0;
}

int Fixed::operator>=(const Fixed& a) {
    if (this->getRawBits() >= a.getRawBits())
        return 1;
    return 0;
}

int Fixed::operator<=(const Fixed& a) {
    if (this->getRawBits() <= a.getRawBits())
        return 1;
    return 0;
}

int Fixed::operator==(const Fixed& a) {
    if (this->getRawBits() == a.getRawBits())
        return 1;
    return 0;
}

int Fixed::operator!=(const Fixed& a) {
    if (this->getRawBits() != a.getRawBits())
        return 1;
    return 0;
}

// INCREMENT/DECREMENT OPERATORS

// PRE

Fixed   &Fixed::operator++(void) {
    ++this->_value;
    return *this;
}

Fixed   &Fixed::operator--(void) {
    --this->_value;
    return *this;
}

// POST

Fixed   Fixed::operator++(int) {
    Fixed tmp(*this);

    ++this->_value;
    return tmp;
}

Fixed   Fixed::operator--(int) {
    Fixed tmp(*this);

    --(*this);
    return tmp;
}

// OVERLOADED MEMBER FUNCTIONS

Fixed   &Fixed::min(Fixed &a, Fixed &b) {
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

Fixed   &Fixed::min(const Fixed &a, const Fixed &b) {
    if (a.getRawBits() < b.getRawBits())
        return (Fixed&)a;
    return (Fixed&)b;
}

Fixed   &Fixed::max(Fixed &a, Fixed &b) {
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}

Fixed   &Fixed::max(const Fixed &a, const Fixed &b) {
    if (a.getRawBits() > b.getRawBits())
        return (Fixed&)a;
    return (Fixed&)b;
}

//  FUNC

int Fixed::getRawBits (void) const {
    // std::cout << "getRawBits member function called" << std::endl;
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
