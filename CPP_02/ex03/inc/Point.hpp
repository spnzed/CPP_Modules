/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:24:33 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/18 17:10:25 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "../inc/Fixed.hpp"

class Point {
    private:
        Fixed const _x;
        Fixed const _y;
    public:
        Point ( void );
        Point ( const float x, const float y);
        Point ( const Point& a);
        Point &operator=( const Point& a);
        ~Point ( void );

        Fixed getX(void) const;
        Fixed getY(void) const;
};

bool bsp( Point const a,  Point const b, Point const c, Point const point);
