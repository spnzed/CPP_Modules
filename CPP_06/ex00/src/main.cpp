/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:36:33 by aaespino          #+#    #+#             */
/*   Updated: 2024/10/07 13:58:19 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

// int main() {
//     std::string testValues[] = {
//         "42",           // int
//         "4.2",          // double
//         "4.2f",         // float
//         "a",            // char
//         "nan",          // Not a Number
//         "+inf",         // Positive infinity
//         "-inf",         // Negative infinity
//         "2147483647",   // Max int
//         "-2147483648",  // Min int
//         "9999999999",   // Out of int range
//         "-9999999999",  // Out of int range (negative)
//         "0",            // Zero
//         ".42",          // Invalid format
//         "42.",          // Invalid format
//         "+42",          // Positive int with sign
//         "-42",          // Negative int
//         "99999999f"     // Large float
//     };

//     for (unsigned long i = 0; i < sizeof(testValues) / sizeof(std::string); ++i) {
//         std::cout << "Testing: " << testValues[i] << std::endl;
//         ScalarConverter::convert(testValues[i]);
//         std::cout << "------------------------" << std::endl;
//     }

//     return 0;
// }

int main (int argc, char **argv) {
	if (argc == 2) {
		ScalarConverter::convert(argv[1]);
	} else {
		std::cerr << "Error: Please give just one argument." << std::endl;
	}
	return 0;
}
