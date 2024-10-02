/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:23:53 by aaespino          #+#    #+#             */
/*   Updated: 2024/10/02 18:28:51 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Array.hpp"
#include <iostream>

int main() {
    try {
        // Test default constructor
        Array<int> arr1;
        std::cout << "Size of arr1: " << arr1.size() << std::endl; // Should be 0

        // Test constructor with size
        Array<int> arr2(5);
        std::cout << "Size of arr2: " << arr2.size() << std::endl; // Should be 5

        // Assign values
        for (unsigned int i = 0; i < arr2.size(); ++i) {
            arr2[i] = i * 10;
        }

        // Display values
        for (unsigned int i = 0; i < arr2.size(); ++i) {
            std::cout << "arr2[" << i << "] = " << arr2[i] << std::endl;
        }

        // Test copy constructor
        Array<int> arr3(arr2);
        std::cout << "Size of arr3 (copy of arr2): " << arr3.size() << std::endl; // Should be 5
        arr3[0] = 100; // Change arr3, should not affect arr2
        std::cout << "arr2[0] after modifying arr3: " << arr2[0] << std::endl; // Should still be 0

        // Test assignment operator
        Array<int> arr4;
        arr4 = arr2;
        arr4[1] = 200; // Change arr4, should not affect arr2
        std::cout << "arr2[1] after modifying arr4: " << arr2[1] << std::endl; // Should still be 10

        // Test out of bounds access
        try {
            std::cout << arr2[5] << std::endl; // Should throw exception
        } catch (const std::exception& e) {
            std::cerr << "Exception caught: Out of bounds access!" << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
