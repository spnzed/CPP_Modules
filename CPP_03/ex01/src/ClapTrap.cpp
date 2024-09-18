/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:22 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/18 11:57:58 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

#include <iostream>
#include <string>

ClapTrap::ClapTrap(void) : _name("ClapTrap_Unnamed"), _hit_points(10), _energy_points(10), _attack_damage(0) {
    std::cout << "ClapTrap gets born by the name: " << this->_name << "!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {
    std::cout << "ClapTrap gets born by the name: " << this->_name << "!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& a) {
    *this = a;
}

ClapTrap::~ClapTrap(void) {
    std::cout << "ClapTrap " << this->_name << " has been destroyed." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& a) {
    if (this != &a) {
        this->_name = a._name;
        this->_hit_points = a._hit_points;
        this->_energy_points = a._energy_points;
        this->_attack_damage = a._attack_damage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (this->_hit_points > 0 && this->_energy_points > 0) {
        --this->_energy_points;
        std::cout << "\033[31m" << "ClapTrap " << this->_name << " attacks " << target;
        std::cout << ", causing " << this->_attack_damage << " points of damage !" << "\033[0m" << std::endl;
    }
    else if (this->_hit_points <= 0) {
        std::cout << "ClapTrap " << this->_name << " can't attack! No hit points left."; 
        std::cout << std::endl;
    } else {
        std::cout << "ClapTrap " << this->_name << " can't attack! No energy left."; 
        std::cout << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if ((int)amount > this->_hit_points)
        this->_hit_points = amount;
    if (this->_hit_points > 0) {
        this->_hit_points -= amount;
        std::cout << "\033[33m" << "ClapTrap " << this->_name << " takes " << amount;
        std::cout << " points of damage ! (" << this->_hit_points;
        std::cout << " hit points left)." << "\033[0m" << std::endl;
        if (this->_hit_points == 0)
            std::cout << "\033[31m" << "ClapTrap " << this->_name << " is dead." << "\033[0m" << std::endl;
    } else {
        std::cout << "ClapTrap " << this->_name << " can't take damage! " << this->_name << " is dead."; 
        std::cout << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_hit_points > 0 && this->_energy_points > 0) {
        this->_hit_points += amount;
        --this->_energy_points;
        std::cout << "\033[32m" << "ClapTrap " << this->_name << " gets repaired a total of " << amount;
        std::cout << " hit points !" << "\033[0m" << std::endl;
    } else {
        if (this->_energy_points > 0 && !this->_hit_points) {
            std::cout << "ClapTrap " << this->_name << " can't attack. He's dead." << std::endl;
        } else {
            std::cout << "ClapTrap " << this->_name << " can't attack. No hit points left." << std::endl;
        }
    }
}

std::string ClapTrap::getName(void) const {
    return this->_name;
}

int ClapTrap::getHitPoints(void) {
    return this->_hit_points;
}

int ClapTrap::getEnergyPoints(void) {
    return this->_energy_points;
}

int ClapTrap::getAttackDamage(void) {
    return this->_attack_damage;
}
