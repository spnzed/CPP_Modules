/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:58:29 by aaronespino       #+#    #+#             */
/*   Updated: 2024/11/26 18:00:04 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

int main (int argc, char **argv) {

    RPN rpn(argv[1]);

    if (argc == 2) {
        try {
            rpn.calculateRPN();
        } catch (std::runtime_error &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    } else {
        std::cout << "Error: Invalid input." << std::endl;
    }

    return 0;
}
