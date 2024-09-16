/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:22 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/08 18:12:43 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iostream>
#include <string>

FragTrap::FragTrap (std::string name) {//: _name(name), _hit_points(100), _energy_points(50), _attack_damage(20){

    this->_name = name;
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
    
    std::cout << "FragTrap gets born by the name: " << this->_name << "!" << std::endl;
}

FragTrap::FragTrap (void) {//: _name("Default_default"), _hit_points(100), _energy_points(50), _attack_damage(20){

    this->_name = "FragTrap_default";
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
    
    std::cout << "FragTrap gets born by the name: " << this->_name << "!" << std::endl;
}

FragTrap::~FragTrap (void) {
    std::cout << "FragTrap " << this->_name << " has been destroyed." << std::endl;
}

// void    FragTrap::attack(const std::string& target) {
//     if (this->_hit_points > 0 && this->_energy_points > 0) {
//         --this->_energy_points;
//         std::cout << "FragTrap " << this->_name << " attacks " << target;
//         std::cout << ", causing " << this->_attack_damage <<  " points of damage !" << std::endl;
//     }
//     else if (this->_hit_points <= 0) {
//         std::cout << "FragTrap " << this->_name << " can't attack! No hit points left."; 
//         std::cout << std::endl;
//     } else {
//         std::cout << "FragTrap " << this->_name << " can't attack! No energy left."; 
//         std::cout << std::endl;
//     }
// }

void    FragTrap::highFivesGuys(void) {
    if (this->_hit_points > 0 && this->_energy_points > 0) {
        std::cout << "FragTrap Requests a High Five! ✋ :)" << std::endl;
    } else if (this->_hit_points <= 0) {
        std::cout << "FragTrap " << this->_name << " can't raise the hand! :( No hit points left."; 
        std::cout << std::endl;
    } else {
        std::cout << "FragTrap " << this->_name << " can't raise the hand! :( No energy left."; 
        std::cout << std::endl;
    }
}
