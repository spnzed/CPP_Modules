/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:22 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/18 12:47:05 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"

#include <iostream>
#include <string>

FragTrap::FragTrap(void) {
    this->_name = "FragTrap_default";
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
    
    std::cout << "\033[35m" << "FragTrap gets born by the name: " << this->_name << "!" << "\033[0m" << std::endl;
}

FragTrap::FragTrap(std::string name) {
    this->_name = name;
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
    
    std::cout << "\033[35m" << "FragTrap gets born by the name: " << this->_name << "!" << "\033[0m" << std::endl;
}

FragTrap::FragTrap(const FragTrap& a) {
    *this = a;
}

FragTrap::~FragTrap(void) {
    std::cout << "\033[35m" << "FragTrap " << this->_name << " has been destroyed." << "\033[0m" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& a) {
    if (this != &a) {
        this->_name = a._name;
        this->_hit_points = a._hit_points;
        this->_energy_points = a._energy_points;
        this->_attack_damage = a._attack_damage;
    }
    return *this;
}

void FragTrap::highFivesGuys(void) {
    if (this->_hit_points > 0 && this->_energy_points > 0) {
        std::cout << "\033[32m" << "FragTrap Requests a High Five! ✋ :)" << "\033[0m" << std::endl;
    } else if (this->_hit_points <= 0) {
        std::cout << "\033[33m" << "FragTrap " << this->_name << " can't raise the hand! :( No hit points left." << "\033[0m" << std::endl;
    } else {
        std::cout << "\033[33m" << "FragTrap " << this->_name << " can't raise the hand! :( No energy left." << "\033[0m" << std::endl;
    }
}
