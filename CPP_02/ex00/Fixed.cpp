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

//     public:
//         Fixed (void);
//         Fixed (int a);
//         Fixed (void);
//         ~Fixed (void);
//         int getRawBits (void) const;
//         int setRawBits (int const raw) const;
//     private:
//         int                 value;
//         static const int    fractional;
// };

Fixed::Fixed (void) {
    cout << "Default constructor called" << endl;
    this->_value = 0;
    this->_fractional = 0;
}

Fixed::Fixed (int a) {
    cout << "Copy constructor called" << endl;
}

Fixed::Fixed (int a) {
    cout << "Copy assignment operator called" << endl;
}

Fixed::~Fixed (void) {
    cout << "Destructor called" << endl;
}
