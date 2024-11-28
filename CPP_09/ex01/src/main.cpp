/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:58:29 by aaronespino       #+#    #+#             */
/*   Updated: 2024/11/28 13:56:17 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

int main (int argc, char **argv) {

    if (argc == 2 && std::string(argv[1]).size() > 0) {
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
