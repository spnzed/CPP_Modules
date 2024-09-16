/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/16 15:07:44 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Fixed.hpp"

int main (void) {
    Fixed       a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );
    Fixed const e( -42.0f );

    a = Fixed( 1234.4321f );

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "e is " << e << std::endl;


    std::cout << "INTEGRER" << std::endl;

    std::cout << "a is " << a.toInt() << " as integrer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integrer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integrer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integrer" << std::endl;
    std::cout << "e is " << e.toInt() << " as integrer" << std::endl;

    std::cout << "FLOAT" << std::endl;

    std::cout << "a is " << a.toFloat() << " as float" << std::endl;
    std::cout << "b is " << b.toFloat() << " as float" << std::endl;
    std::cout << "c is " << c.toFloat() << " as float" << std::endl;
    std::cout << "d is " << d.toFloat() << " as float" << std::endl;
    std::cout << "e is " << e.toFloat() << " as float" << std::endl;

    return 0;
}
