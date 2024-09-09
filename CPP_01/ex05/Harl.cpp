/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:34:40 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/08 14:12:58 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <string>
#include <iostream>
using namespace std;

Harl::Harl (void) {
    Harl::_ComplainCode[0] = "DEBUG";
    Harl::_ComplainCode[1] = "INFO";
    Harl::_ComplainCode[2] = "WARNING";
    Harl::_ComplainCode[3] = "ERROR";
    Harl::_levels[0] = &Harl::_debug;
    Harl::_levels[1] = &Harl::_info;
    Harl::_levels[2] = &Harl::_warning;
    Harl::_levels[3] = &Harl::_error;
}

Harl::~Harl (void) {}

void Harl::complain (std::string level) {
    for (int i = 0; i < 4; i++) {
        if (_ComplainCode[i] == level)
            (this->*_levels[i])();
    }
}

void Harl::_debug (void) {
    cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << endl;
}

void Harl::_info (void) {
    cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << endl;
}

void Harl::_warning (void) {
    cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month" << endl;
}

void Harl::_error (void) {
    cout << "This is unacceptable! I want to speak to the manager now." << endl;
}