/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:22 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/08 18:12:43 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>
#include <string>

ClapTrap::ClapTrap (std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(1){
    std::cout << "ClapTrap gets born by the name: " << this->_name << "!" << std::endl;
}

ClapTrap::~ClapTrap (void) {
    std::cout << "ClapTrap " << this->_name << " has been destroyed." << std::endl;
}

void    ClapTrap::attack(const std::string& target) {
    if (this->_hit_points > 0 && this->_energy_points > 0) {
        --this->_energy_points;
        std::cout << "ClapTrap " << this->_name << " attacks " << target;
        std::cout << ", causing " << this->_attack_damage <<  " points of damage !" << std::endl;
    }
    else if (this->_hit_points <= 0) {
        std::cout << "ClapTrap " << this->_name << " can't attack! No hit points left."; 
        std::cout << std::endl;
    } else {
        std::cout << "ClapTrap " << this->_name << " can't attack! No energy left."; 
        std::cout << std::endl;
    }
}

void    ClapTrap::takeDamage(unsigned int amount) {
    if (amount > this->_hit_points)
        this->_hit_points = amount;
    if (this->_hit_points > 0) {
        this->_hit_points -= amount;
        std::cout << "ClapTrap " << this->_name << " takes " << amount;
        std::cout << " points of damage ! (" << this->_hit_points;
        std::cout << " hit points left)." << std::endl;
        if (this->_hit_points == 0)
            std::cout << "ClapTrap " << this->_name << " is dead." << std::endl;
    } else {
        std::cout << "ClapTrap " << this->_name << " can't take damage! " << this->_name << " is dead."; 
        std::cout << std::endl;
    }
}

void    ClapTrap::beRepaired(unsigned int amount) {
    if (this->_hit_points > 0 && this->_energy_points > 0) {
        this->_hit_points += amount;
        --this->_energy_points;
        std::cout << "ClapTrap " << this->_name << " gets repaired a total of " << amount;
        std::cout << " hit points !" << std::endl;
    } else {
        if (this->_energy_points > 0 && !this->_hit_points) {
            std::cout << "ClapTrap " << this->_name << " can't attack. He's dead." << std::endl;
        } else {
            std::cout << "ClapTrap " << this->_name << " can't attack. No hit points left." << std::endl;
        }
    }
}

int     ClapTrap::getAttack(void) {
    return this->_attack_damage;
}
