/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:23:53 by aaespino          #+#    #+#             */
/*   Updated: 2024/10/09 16:05:58 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Array.hpp"
#include <iostream>

int main() {
    try {
        // Test default constructor (empty array)
        std::cout << "\033[32m" << "=== Test 1: Create Empty Array (Default Constructor) ===" << "\033[0m" << std::endl;
        Array<int> arr1;
        std::cout << "Size of arr1: " << arr1.size() << std::endl; // Should be 0
        std::cout << "Is arr1 empty? " << (arr1.size() == 0 ? "Yes" : "No") << std::endl; // Should print Yes

        // Test constructor with specific size
        std::cout << "\033[32m" << "=== Test 2: Create Array with Specific Size ===" << "\033[0m" << std::endl;
        Array<int> arr2(5);
        std::cout << "Size of arr2: " << arr2.size() << std::endl; // Should be 5

        // Display values
        std::cout << "\033[32m" << "=== Test 3: Assign and Display Values (int array) ===" << "\033[0m" << std::endl;
        // Assign values
        for (unsigned int i = 0; i < arr2.size(); ++i) {
            arr2[i] = i * 10;
        }
        for (unsigned int i = 0; i < arr2.size(); ++i) {
            std::cout << "arr2[" << i << "] = " << arr2[i] << std::endl;
        }

        // Test with complex type (std::string)
        std::cout << "\033[32m" << "=== Test 4: Create Array of std::string ===" << "\033[0m" << std::endl;
        Array<std::string> arr3(3);

        // Display std::string values
        std::cout << "\033[32m" << "=== Test 5: Assign and Display Values (std::string array) ===" << "\033[0m" << std::endl;
        arr3[0] = "Hello";
        arr3[1] = "World";
        arr3[2] = "C++";
        for (unsigned int i = 0; i < arr3.size(); ++i) {
            std::cout << "arr3[" << i << "] = " << arr3[i] << std::endl;
        }

        // Test copy constructor with std::string
        std::cout << "\033[32m" << "=== Test 6: Copy Constructor (std::string array) ===" << "\033[0m" << std::endl;
        Array<std::string> arr4(arr3);
        std::cout << "Size of arr4 (copy of arr3): " << arr4.size() << std::endl;
        std::cout << "arr4[0]: " << arr4[0] << std::endl;

        // Test assignment operator with std::string
        std::cout << "\033[32m" << "=== Test 7: Assignment Operator (std::string array) ===" << "\033[0m" << std::endl;
        Array<std::string> arr5;
        arr5 = arr3;
        std::cout << "Size of arr5 (assignment from arr3): " << arr5.size() << std::endl;
        std::cout << "arr5[1]: " << arr5[1] << std::endl;

        // Test out of bounds access
        std::cout << "\033[32m" << "=== Test 8: Out of Bounds Access ===" << "\033[0m" << std::endl;
        try {
            std::cout << arr2[5] << std::endl; // Should throw exception
        } catch (const std::exception& e) {
            std::cerr << "\033[31m" << "Exception caught: Out of bounds access!" << "\033[0m" << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "\033[31m" << "Exception caught: " << e.what() << "\033[0m" << std::endl;
    }

    return 0;
}
