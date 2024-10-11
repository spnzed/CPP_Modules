/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:47:12 by aaespino          #+#    #+#             */
/*   Updated: 2024/10/11 18:01:26 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/iter.hpp"

int main() {
    // Array of ints
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLength = sizeof(intArray) / sizeof(intArray[0]);
    std::cout << "Array de enteros: ";
    iter(intArray, intLength, print);
    std::cout << std::endl;

    // Array of double
    double doubleArray[] = {1.1, 2.2, 3.3};
    size_t doubleLength = sizeof(doubleArray) / sizeof(doubleArray[0]);
    std::cout << "Array de doubles: ";
    iter(doubleArray, doubleLength, print);
    std::cout << std::endl;

    // Array of char
    char charArray[] = {'A', 'B', 'C', 'D'};
    size_t charLength = sizeof(charArray) / sizeof(charArray[0]);
    std::cout << "Array de caracteres: ";
    iter(charArray, charLength, print);
    std::cout << std::endl;

    return 0;
}
