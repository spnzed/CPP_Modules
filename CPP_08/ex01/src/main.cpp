/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:32:11 by aaespino          #+#    #+#             */
/*   Updated: 2024/10/11 14:17:13 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"
#include <cstdlib> // Para std::rand y std::srand
#include <ctime>   // Para std::time
#include <set>

// Function to print titles with color
void printTitle(const std::string& title, const std::string& colorCode) {
    std::cout << colorCode << title << "\033[0m" << std::endl;
}

int main() {
    // Original Tests
    Span sp = Span(10);

    // Title for adding numbers one by one
    printTitle("=== Test: Adding Numbers One by One ===", "\033[1;34m"); // Blue

    // Adding numbers one by one
    try {
        sp.addNumber(100);      // A large number
        sp.addNumber(-50);      // A negative number
        sp.addNumber(25);       // An intermediate number
        sp.addNumber(75);       // A number that is a multiple of 25
        sp.addNumber(5);        // A small number
        std::cout << "Successfully added numbers to the Span." << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: Adding numbers one by one" << std::endl;
    }

    // Title for adding many numbers at once
    printTitle("=== Test: Adding Many Numbers at Once ===", "\033[1;34m"); // Blue

    // Adding many numbers at once
    std::vector<int> numbers;
    numbers.push_back(10000);  // An immense number
    numbers.push_back(-100);    // A large negative number
    numbers.push_back(10);      // Another small number
    numbers.push_back(15);      // A number close to 10
    numbers.push_back(40);      // An intermediate number

    try {
        sp.addManyNumbers(numbers.begin(), numbers.end());
        std::cout << "Successfully added multiple numbers to the Span." << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: Adding many numbers" << std::endl;
    }

    // Título para añadir muchos números a la vez
    printTitle("=== Test: Adding Many Random Numbers (10000) at Once ===", "\033[1;34m"); // Azul

    // Inicializa el generador de números aleatorios
    std::srand(static_cast<unsigned>(std::time(0)));
    // Añadiendo muchos números aleatorios
    std::set<int> uniqueNumbers;
    int i = 0;
    while (uniqueNumbers.size() < 10000) {
        int randomNum;
        if (i % 2 == 0)
            randomNum = std::rand() % 100000; // Cambia el rango según lo desees
        else
            randomNum = -std::rand() % 100000;
        uniqueNumbers.insert(randomNum); // Solo insertará si es único
        i++;
    }

    std::vector<int> bignumbers(uniqueNumbers.begin(), uniqueNumbers.end());

    Span big = Span(10000); // Asegúrate de que tu objeto Span esté correctamente definido

    try {
        big.addManyNumbers(bignumbers.begin(), bignumbers.end());
        std::cout << "Successfully added 10,000 unique random numbers to the Span." << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: Adding many numbers - " << e.what() << std::endl;
    }

    // Title for calculating spans
    printTitle("=== Test: Calculating Shortest and Longest Span ===", "\033[1;34m"); // Blue

    // Printing the results of the shortestSpan and longestSpan functions
    try {
        unsigned int shortest = sp.shortestSpan();
        unsigned int longest = sp.longestSpan();

        std::cout << "Shortest Span: " << shortest << std::endl;
        std::cout << "Longest Span: " << longest << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: (Calculating spans" << std::endl;
    }

    // Title for calculating spans
    printTitle("=== Test: Calculating Shortest and Longest Span (10000) ===", "\033[1;34m"); // Blue

    // Printing the results of the shortestSpan and longestSpan functions
    try {
        unsigned int shortest = big.shortestSpan();
        unsigned int longest = big.longestSpan();

        std::cout << "Shortest Span: " << shortest << std::endl;
        std::cout << "Longest Span: " << longest << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: (Calculating spans" << std::endl;
    }

    // Testing Exceptions
    printTitle("=== Test: Adding Numbers with Exception Handling ===", "\033[1;31m"); // Red

    // Adding numbers one by one to trigger exception
    Span spEx = Span(5);  // Smaller capacity for testing exception
    try {
        spEx.addNumber(1);
        spEx.addNumber(2);
        spEx.addNumber(3);
        spEx.addNumber(4);
        spEx.addNumber(5);
        // This should throw an exception
        spEx.addNumber(6);
    } catch (const std::exception &e) {
        std::cerr << "Exception: Adding numbers one by one" << std::endl;
    }

    printTitle("=== Test: Adding Many Numbers with Exception Handling ===", "\033[1;31m"); // Red

    // Adding many numbers at once to trigger exception
    std::vector<int> excessNumbers;
    excessNumbers.push_back(1);
    excessNumbers.push_back(2);
    excessNumbers.push_back(3);
    excessNumbers.push_back(4);
    excessNumbers.push_back(5);
    excessNumbers.push_back(6); // Exceeds capacity

    Span spExMany = Span(5);  // Smaller capacity for testing exception

    try {
        spExMany.addManyNumbers(excessNumbers.begin(), excessNumbers.end());
    } catch (const std::exception &e) {
        std::cerr << "Exception: Adding many numbers" << std::endl;
    }

    // Title for calculating spans with exceptions
    printTitle("=== Test: Calculating Spans with Exception Handling ===", "\033[1;31m"); // Red

    try {
        unsigned int shortest = spExMany.shortestSpan();
        unsigned int longest = spExMany.longestSpan();

        std::cout << "Shortest Span: " << shortest << std::endl;
        std::cout << "Longest Span: " << longest << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: Calculating spans" << std::endl;
    }

    return 0;
}
