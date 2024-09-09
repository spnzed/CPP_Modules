/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:14:22 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/08 14:18:18 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
using namespace std;

int main (void) {
    Harl test;

    cout << "Testing DEBUG..." << endl;
    test.complain("DEBUG");
    cout << "Testing INFO..." << endl;
    test.complain("INFO");
    cout << "Testing WARNING..." << endl;
    test.complain("WARNING");
    cout << "Testing ERROR..." << endl;
    test.complain("ERROR");

    return 0;
}