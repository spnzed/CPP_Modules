/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:22 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/08 18:12:43 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include <iostream>
#include <string>

ScavTrap::ScavTrap (std::string name) {//: _name(name), _hit_points(100), _energy_points(50), _attack_damage(20){

    this->_name = name;
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
    
    std::cout << "ScavTrap gets born by the name: " << this->_name << "!" << std::endl;
}

ScavTrap::ScavTrap (void) {//: _name("Default_default"), _hit_points(100), _energy_points(50), _attack_damage(20){

    this->_name = "ScavTrap_default";
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
    
    std::cout << "ScavTrap gets born by the name: " << this->_name << "!" << std::endl;
}

ScavTrap::~ScavTrap (void) {
    std::cout << "ScavTrap " << this->_name << " has been destroyed." << std::endl;
}

void    ScavTrap::attack(const std::string& target) {
    if (this->_hit_points > 0 && this->_energy_points > 0) {
        --this->_energy_points;
        std::cout << "ScavTrap " << this->_name << " attacks " << target;
        std::cout << ", causing " << this->_attack_damage <<  " points of damage !" << std::endl;
    }
    else if (this->_hit_points <= 0) {
        std::cout << "ScavTrap " << this->_name << " can't attack! No hit points left."; 
        std::cout << std::endl;
    } else {
        std::cout << "ScavTrap " << this->_name << " can't attack! No energy left."; 
        std::cout << std::endl;
    }
}

void    ScavTrap::guardGate(void) {
    if (this->_hit_points > 0 && this->_energy_points > 0) {
        std::cout << "ScavTrap is now in Gate keeper mode";
    }
    else if (this->_hit_points <= 0) {
        std::cout << "ScavTrap " << this->_name << " can't guard! No hit points left."; 
        std::cout << std::endl;
    } else {
        std::cout << "ScavTrap " << this->_name << " can't guard! No energy left."; 
        std::cout << std::endl;
    }
}
