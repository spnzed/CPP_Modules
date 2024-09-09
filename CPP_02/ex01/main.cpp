/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/08 18:04:12 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

using namespace std;

int main (void) {
    Fixed       a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );

    a = Fixed( 1234.4321f );

    cout << a.getRawBits() << endl;
    cout << b.getRawBits() << endl;
    cout << c.getRawBits() << endl;
    cout << c.getRawBits() << endl;

    cout << "a is " << a.toInt() << " as integrer" << endl;
    cout << "b is " << a.toInt() << " as integrer" << endl;
    cout << "c is " << a.toInt() << " as integrer" << endl;
    cout << "d is " << a.toInt() << " as integrer" << endl;

    return 0;
}