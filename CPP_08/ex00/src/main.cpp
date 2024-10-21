/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:32:11 by aaespino          #+#    #+#             */
/*   Updated: 2024/10/21 14:30:28 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"

#include <deque>
#include <list>
#include <vector>

// Function to print titles with color
void printTitle(const std::string& title, const std::string& colorCode) {
    std::cout << colorCode << title << "\033[0m" << std::endl;
}

int main() {
    // Create containers and add some values using push_back
    std::vector<int> innerVector;
    innerVector.push_back(1);
    innerVector.push_back(2);
    innerVector.push_back(3);
    innerVector.push_back(4);

    std::deque<int> innerDeque;
    innerDeque.push_back(1);
    innerDeque.push_back(2);
    innerDeque.push_back(3);
    innerDeque.push_back(4);

    std::list<int> innerList;
    innerList.push_back(1);
    innerList.push_back(2);
    innerList.push_back(3);
    innerList.push_back(4);

    // Testing with vector
    printTitle("=== Test with vector, Searching for value 4 ===", "\033[1;32m"); // Green
    try {
        std::cout << "Found: " << easyfind(innerVector, 4) << std::endl;
    } catch (std::out_of_range& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    printTitle("=== Test with vector, Searching for value 5 ===", "\033[1;31m"); // Red
    try {
        std::cout << "Found: " << easyfind(innerVector, 5) << std::endl;
    } catch (std::out_of_range& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Testing with deque
    printTitle("=== Test with deque, Searching for value 3 ===", "\033[1;32m"); // Green
    try {
        std::cout << "Found: " << easyfind(innerDeque, 3) << std::endl;
    } catch (std::out_of_range& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    printTitle("=== Test with deque, Searching for value 6 ===", "\033[1;31m"); // Red
    try {
        std::cout << "Found: " << easyfind(innerDeque, 6) << std::endl;
    } catch (std::out_of_range& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Testing with list
    printTitle("=== Test with list, Searching for value 2 ===", "\033[1;32m"); // Green
    try {
        std::cout << "Found: " << easyfind(innerList, 2) << std::endl;
    } catch (std::out_of_range& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    printTitle("=== Test with list, Searching for value 7 ===", "\033[1;31m"); // Red
    try {
        std::cout << "Found: " << easyfind(innerList, 7) << std::endl;
    } catch (std::out_of_range& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
