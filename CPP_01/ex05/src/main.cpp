/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:14:22 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/14 17:13:49 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"
#include <iostream>

int main (void) {
    Harl test;

    std::cout << "\033[32m" << "Testing DEBUG..." << "\033[0m" << std::endl;
    test.complain("DEBUG");
    std::cout << "\033[32m" << "Testing INFO..." << "\033[0m" << std::endl;
    test.complain("INFO");
    std::cout << "\033[32m" << "Testing WARNING..." << "\033[0m" << std::endl;
    test.complain("WARNING");
    std::cout << "\033[32m" << "Testing ERROR..." << "\033[0m" << std::endl;
    test.complain("ERROR");

    return 0;
}
