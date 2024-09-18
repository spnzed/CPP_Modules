/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:22 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/18 12:08:34 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

#include <iostream>
#include <string>

ScavTrap::ScavTrap(void) {
    this->_name = "ScavTrap_Unnamed";
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
    
    std::cout << "\033[36m" << "ScavTrap gets born by the name: " << this->_name << "!" << "\033[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name) {
    this->_name = name;
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
    
    std::cout << "\033[36m" << "ScavTrap gets born by the name: " << this->_name << "!" << "\033[0m" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& a) {
    *this = a;
}

ScavTrap::~ScavTrap(void) {
    std::cout <<  "\033[36m" << "ScavTrap " << this->_name << " has been destroyed." << "\033[0m" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& a) {
    if (this != &a) {
        this->_name = a._name;
        this->_hit_points = a._hit_points;
        this->_energy_points = a._energy_points;
        this->_attack_damage = a._attack_damage;
    }
    return *this;
}

void ScavTrap::attack(const std::string& target) {
    if (this->_hit_points > 0 && this->_energy_points > 0) {
        --this->_energy_points;
        std::cout << "\033[31m" << "ScavTrap " << this->_name << " attacks " << target;
        std::cout << ", causing " << this->_attack_damage << " points of damage!" << "\033[0m" << std::endl;
    }
    else if (this->_hit_points <= 0) {
        std::cout << "\033[33m" << "ScavTrap " << this->_name << " can't attack! No hit points left." << "\033[0m" << std::endl;
    } else {
        std::cout << "\033[33m" << "ScavTrap " << this->_name << " can't attack! No energy left." << "\033[0m" << std::endl;
    }
}

void ScavTrap::guardGate(void) {
    if (this->_hit_points > 0 && this->_energy_points > 0) {
        std::cout << "\033[32m" << "ScavTrap is now in Gate keeper mode" << "\033[0m" << std::endl;
    }
    else if (this->_hit_points <= 0) {
        std::cout << "\033[33m" << "ScavTrap " << this->_name << " can't guard! No hit points left." << "\033[0m" << std::endl;
    } else {
        std::cout << "\033[33m" << "ScavTrap " << this->_name << " can't guard! No energy left." << "\033[0m" << std::endl;
    }
}
