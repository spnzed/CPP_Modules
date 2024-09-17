/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:35:01 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/17 19:31:42 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "../inc/Point.hpp"

Point::Point ( void ) : _x(0), _y(0) {
    
}

Point::Point ( const float x, const float y) : _x(x), _y(y) {

}

Point::Point ( const Point& a)  : _x(a._x), _y(a._y) {
}

Point::Point &operator=( const Point& a) {
    if (this != &a) {
        (Fixed)this->_x = a->_x;
        (Fixed)this->_y = a->_y;
    }
    return *this;
}

Point::~Point ( void ) {

}

Point::Fixed const getX(void) {
    return this->_x
}

Point::Fixed const getY(void) {
    return this->_y
}
