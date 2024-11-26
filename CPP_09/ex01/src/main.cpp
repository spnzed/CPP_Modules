/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:58:29 by aaronespino       #+#    #+#             */
/*   Updated: 2024/11/26 18:23:46 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

int main (int argc, char **argv) {

    if (argc == 2 && std::strlen(argv[1]) > 0) {
        try {
            RPN rpn(argv[1]);
            rpn.calculateRPN();
        } catch (std::runtime_error &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    } else {
        std::cout << "Error: Invalid input" << std::endl;
    }
    return 0;
}
