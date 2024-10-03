/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:32:11 by aaespino          #+#    #+#             */
/*   Updated: 2024/10/03 16:41:51 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

int main() {
    Span sp = Span(10);

    // Adding numbers one by one
    try {
        sp.addNumber(100);      // A large number
        sp.addNumber(-50);      // A negative number
        sp.addNumber(25);       // An intermediate number
        sp.addNumber(75);       // A number that is a multiple of 25
        sp.addNumber(5);        // A small number
        
        // Additional number error
        // sp.addNumber(1);  // Adding an additional number
    } catch (const std::exception &e) {
        std::cerr << "Exception: Exceeded the limit of total added numbers." << std::endl;
    }

    // Adding many numbers at once

    std::vector<int> numbers;
    numbers.push_back(10000);  // An immense number
    numbers.push_back(-100);   // A large negative number
    numbers.push_back(10);     // Another small number
    numbers.push_back(15);     // A number close to 10
    numbers.push_back(40);     // An intermediate number

    try {
        sp.addManyNumbers(numbers.begin(), numbers.end());
        // Adding many numbers AGAIN
        // sp.addManyNumbers(numbers.begin(), numbers.end());  
    } catch (const std::exception &e) {
        std::cerr << "Exception: Exceeded the limit of total added numbers." << std::endl;
    }

    // Printing the results of the shortestSpan and longestSpan functions
    try {
        unsigned int shortest = sp.shortestSpan();
        unsigned int longest = sp.longestSpan();

        std::cout << "Shortest Span: " << shortest << std::endl;
        std::cout << "Longest Span: " << longest << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: At least two elements are needed to calculate the span." << std::endl;
    }

    return 0;
}
