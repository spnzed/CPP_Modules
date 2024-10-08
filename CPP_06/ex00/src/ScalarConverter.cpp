/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:59:20 by aaespino          #+#    #+#             */
/*   Updated: 2024/10/08 15:46:50 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

#include <cstdlib>
#include <iostream>
#include <climits>
#include <cctype>   // Para std::isprint

ScalarConverter::ScalarConverter(void) {
}

ScalarConverter::ScalarConverter(const ScalarConverter& a) {
    *this = a;
}

ScalarConverter::~ScalarConverter(void) {
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter& a) {
    if (this != &a) {
    }
    return *this;
}

void ScalarConverter::convert(std::string literal) {

	//	Comprove input
	if (literal == "-inff" || literal == "+inff" || literal == "inff" \
		|| literal == "-inf" || literal == "+inf" || literal == "inf" \
		|| literal == "nan" || literal == "nanf" || literal.size() == 1) {
		;		
	} else {
		int i = 0;
		int end = literal.size();

		if (literal[i] == '.' || literal[end - 1] == '.') {
			std::cout << "char: impossible" << std::endl;
        	std::cout << "int: impossible" << std::endl;
        	std::cout << "float: impossible" << std::endl;
        	std::cout << "double: impossible" << std::endl;
			return ;
		}	
		if (literal[i] == '-' || literal[i] == '+')
			i++;
		if (literal[end - 1] == 'f')
			end--;
		if (end == 0) {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return ;
		}
		for (; i < end ; i++) {
			if (literal[i] != '.') {
				if (!std::isdigit(literal[i])) {
					std::cout << "char: impossible" << std::endl;
					std::cout << "int: impossible" << std::endl;
					std::cout << "float: impossible" << std::endl;
					std::cout << "double: impossible" << std::endl;
					return ;
				}
			}
		}
	}

	// Char to -> x
	if (literal.size() == 1) {
		char c = literal[0];
        int n = static_cast<int>(c);;
        float nfloat = static_cast<float>(c);;
        double ndouble = static_cast<double>(c);;

		std::cout << "char: " << c << std::endl;
        std::cout << "int: " << n << std::endl;
        std::cout << "float: " << nfloat << "f" << std::endl;
        std::cout << "double: " << ndouble << std::endl;

		return ;
	}


	else if (literal.find('.') != std::string::npos) {
		char *end;
		double base = std::strtod(literal.c_str(), &end);  // Usamos strtod para todos los casos de punto decimal
		long comp = static_cast<long>(base);

		// Float or Double to -> x
		if (*end == 'f' && *(end + 1) == '\0') {  // Si termina en 'f' es un float
			float fvalue = static_cast<float>(base);
			int n = static_cast<int>(fvalue);

			if (comp < INT_MIN || comp > INT_MAX) {
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
			} else {
				if (comp < 0 || comp > 127) {
					std::cout << "char: impossible" << std::endl;
				} else if (!std::isprint(n)) {
					std::cout << "char: Non displayable" << std::endl;
				} else {
					char c = static_cast<char>(n);
					std::cout << "char: " << c << std::endl;
				}
				std::cout << "int: " << n << std::endl;
			}
			std::cout << "float: " << fvalue << "f" << std::endl;
			std::cout << "double: " << base << std::endl;

			return ;
		}
		// Double case (sin 'f' al final)
		else if (*end == '\0') {
			float fvalue = static_cast<float>(base);
			int n = static_cast<int>(base);

			if (comp < INT_MIN || comp > INT_MAX) {
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
			} else {
				if (comp < 0 || comp > 127) {
					std::cout << "char: impossible" << std::endl;
				} else if (!std::isprint(n)) {
					std::cout << "char: Non displayable" << std::endl;
				} else {
					char c = static_cast<char>(n);
					std::cout << "char: " << c << std::endl;
				}
				std::cout << "int: " << n << std::endl;
			}
			std::cout << "float: " << fvalue << "f" << std::endl;
			std::cout << "double: " << base << std::endl;

			return ;
		}
	}


	// Int to -> x
	else {

		char *end;

        int n = std::atoi(literal.c_str());
        double ndouble = std::strtod(literal.c_str(), &end);
		long comp = static_cast<long>(ndouble);

		if ((comp < INT_MIN || comp > INT_MAX) || (literal == "nanf" || literal == "nan")) {
        	std::cout << "char: impossible" << std::endl;
        	std::cout << "int: impossible" << std::endl;
		} else {
			if (comp < 0 || comp > 127) {
					std::cout << "char: impossible" << std::endl;
			} else if (!(std::isprint(n))) {
				std::cout << "char: Non displayable" << std::endl;
			} else {
				char c = n;
				std::cout << "char: " << c << std::endl;
			}
			std::cout << "int: " << n << std::endl;
		}

		float nfloat = std::strtof(literal.c_str(), &end);
        std::cout << "float: " << nfloat << "f" << std::endl;
        std::cout << "double: " << ndouble << std::endl;
	}
}
