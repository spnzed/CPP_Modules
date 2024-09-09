/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:09:03 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/08 18:12:57 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
using namespace std;

Fixed::Fixed (void) : _value(0) {
    cout << "Default constructor called" << endl;
}

Fixed::Fixed (const int& a) : _value(a) {
    cout << "Int constructor called" << endl;
}

Fixed::Fixed (const float& a) : _value(a) {
    cout << "Float constructor called" << endl;
}

Fixed::Fixed (const Fixed& a) {
    cout << "Copy constructor called" << endl;
    *this = a;
}

Fixed &Fixed::operator=(const Fixed& a) {
    cout << "Copy assignment operator called" << endl;
    if (this != &a)
        this->setRawBits (a.getRawBits());
    return *this;
}

Fixed &Fixed::operator<<(const Fixed& a); {
    return std::to_string << a.getRawBits();
}


Fixed::~Fixed (void) {
    cout << "Destructor called" << endl;
}

int Fixed::getRawBits (void) const {
    cout << "getRawBits member function called" << endl;
    return this->_value;
}

void Fixed::setRawBits (int const raw) {
    this->_value = raw;
}

float Fixed::toFloat( void ) const {
    
}

int Fixed::toInt( void ) const {

}
