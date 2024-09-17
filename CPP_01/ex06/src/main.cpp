/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:14:22 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/16 12:05:43 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"
#include <iostream>

int main (int argc, char **argv) {
    Harl test;

    if (argc == 2) {
        test.complain(argv[1]);
    } else if (argc == 1) {
        std::cout << "\033[35m" << "Error. Harl expects you to say something. Preferably <DEBUG> <INFO> <WARNING> <ERROR> ;)" << "\033[0m" << std::endl;
    } else {
        std::cout << "\033[35m" << "Error. Harl just accepts one order at a time." << "\033[0m" << std::endl;
    }

    return 0;
}
