/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:34:40 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/16 11:51:02 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"
#include <string>
#include <iostream>

std::string Harl::_ComplainCode[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};                             // Inicialización del array estático
void (Harl::*Harl::_levels[4])(void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};   // Inicialización de los punteros a funciones

Harl::Harl (void) {}

Harl::~Harl (void) {}

void Harl::complain (std::string level) {
    for (int i = 0; i < 4; i++) {
        if (_ComplainCode[i] == level)
            (this->*_levels[i])();
    }
}

void Harl::_debug (void) {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::_info (void) {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::_warning (void) {
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month" << std::endl;
}

void Harl::_error (void) {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
