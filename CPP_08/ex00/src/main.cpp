/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:32:11 by aaespino          #+#    #+#             */
/*   Updated: 2024/10/07 15:24:38 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"

// Function to print titles with color
void printTitle(const std::string& title, const std::string& colorCode) {
    std::cout << colorCode << title << "\033[0m" << std::endl;
}

int main() {
    // Create a vector and add some values
    std::vector<int> innerVector;
    innerVector.push_back(1);
    innerVector.push_back(2);
    innerVector.push_back(3);
    innerVector.push_back(4);

    // Title for the first test (Value found)
    printTitle("=== Test: Searching for value 4 ===", "\033[1;32m"); // Green

    // Case where the value exists in the container
    try {
        std::cout << "Found: " << easyfind(innerVector, 4) << std::endl;
    } catch (std::out_of_range& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Title for the second test (Value not found)
    printTitle("=== Test: Searching for value 5 ===", "\033[1;31m"); // Red

    // Case where the value does not exist in the container
    try {
        std::cout << "Found: " << easyfind(innerVector, 5) << std::endl;
    } catch (std::out_of_range& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
