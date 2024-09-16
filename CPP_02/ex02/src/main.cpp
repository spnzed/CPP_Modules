/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/16 15:09:30 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Fixed.hpp"

int main (void) {

    Fixed       a;
    Fixed const b( Fixed( 5.05f ) * Fixed ( 2 ) );
    Fixed c( 2 );

    Fixed const d( Fixed( 2.01f ) * Fixed ( 2 ) );
    Fixed const f( Fixed( 21.21f ) * Fixed ( 2 ) );


    std::cout << "\033[32m" << "Comparison operators" << "\033[0m"<< std::endl;

    if (a < b)
        std::cout << "Comparison < works" << std::endl;
    if (!(a > b))
        std::cout << "Comparison > works" << std::endl;
    if (a <= b)
        std::cout << "Comparison <= works" << std::endl;
    if (!(a >= b))
        std::cout << "Comparison >= works" << std::endl;
    if (!(a == b))
        std::cout << "Comparison == works" << std::endl;
    if (a != b)
        std::cout << "Comparison != works" << std::endl;

    std::cout << "\033[32m" << "Arithmetic operators" << "\033[0m"<< std::endl;

    std::cout << a + c << std::endl;
    std::cout << a - c << std::endl;
    std::cout << c * 2 << std::endl;
    std::cout << c / 1 << std::endl;

    std::cout << "\033[32m" << "Increment/Decrement operators" << "\033[0m"<< std::endl;

    
    std::cout << ++a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << "\033[35m" << "↑↑↑↑ Post increment" << "\033[0m"<< std::endl;

    std::cout << --c << std::endl;
    std::cout << c-- << std::endl;
    std::cout << c << std::endl;
    std::cout << "\033[35m" << "↑↑↑↑ Post decrement" << "\033[0m"<< std::endl;

    std::cout << "\033[32m" << "Declaration with multiplication inside (floats)" << "\033[0m"<< std::endl;

    std::cout << b << std::endl;
    
    std::cout << "\033[32m" << "Division by 0" << "\033[0m"<< std::endl;

    std::cout << a / 0 << std::endl;

    std::cout << "\033[32m" << "Min/Max" << "\033[0m"<< std::endl;
    std::cout << Fixed::max( c, b ) << std::endl;
    std::cout << Fixed::min( c, b ) << std::endl;

    std::cout << "\033[32m" << "Min/Max Const" << "\033[0m"<< std::endl;
    std::cout << Fixed::max( d, f ) << std::endl;
    std::cout << Fixed::min( d, f ) << std::endl;

    return 0;
}

// int main (void) {

//     Fixed       a;
//     Fixed const b( Fixed( 5.05f ) * Fixed ( 2 ) );

//     std::cout << a << std::endl;
//     std::cout << ++a << std::endl;
//     std::cout << a << std::endl;
//     std::cout << a++ << std::endl;
//     std::cout << a << std::endl;
    
//     std::cout << b << std::endl;
    
//     std::cout << a / 0 << std::endl;

//     std::cout << Fixed::max( a, b ) << std::endl;

//     return 0;
// }
