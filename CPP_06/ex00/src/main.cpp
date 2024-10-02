/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:36:33 by aaespino          #+#    #+#             */
/*   Updated: 2024/10/02 14:21:03 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

int main (int argc, char **argv) {
	if (argc == 2) {
		ScalarConverter::convert(argv[1]);
	} else {
		std::cerr << "Error: Please one argument." << std::endl;
	}
	return 0;
}