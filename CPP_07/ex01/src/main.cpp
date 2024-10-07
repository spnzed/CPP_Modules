/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:47:12 by aaespino          #+#    #+#             */
/*   Updated: 2024/10/07 14:14:48 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/iter.hpp"

void printInt(int value) {
    std::cout << value << " ";
}

void printDouble(double value) {
    std::cout << value << " ";
}

void printChar(char value) {
    std::cout << value << " ";
}

int main() {
    // Array of ints
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLength = sizeof(intArray) / sizeof(intArray[0]);
    std::cout << "Array de enteros: ";
    iter(intArray, intLength, printInt);
    std::cout << std::endl;

    // Array of double
    double doubleArray[] = {1.1, 2.2, 3.3};
    size_t doubleLength = sizeof(doubleArray) / sizeof(doubleArray[0]);
    std::cout << "Array de doubles: ";
    iter(doubleArray, doubleLength, printDouble);
    std::cout << std::endl;

    // Array of char
    char charArray[] = {'A', 'B', 'C', 'D'};
    size_t charLength = sizeof(charArray) / sizeof(charArray[0]);
    std::cout << "Array de caracteres: ";
    iter(charArray, charLength, printChar);
    std::cout << std::endl;

    return 0;
}
