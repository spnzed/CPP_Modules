/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:03:21 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/19 18:44:09 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : _name("DiamondTrap_default") {
    std::cout << "\033[33m" << "DiamondTrap gets born by the name: " << this->_name << "!" << "\033[0m" << std::endl;

    this->FragTrap::_hit_points = FragTrap::_hit_points;
    this->FragTrap::_attack_damage = FragTrap::_attack_damage;

    this->ScavTrap::_energy_points = ScavTrap::_energy_points;
}

DiamondTrap::DiamondTrap(std::string name) : _name(name) {
    std::cout << "\033[33m" << "DiamondTrap gets born by the name: " << this->_name << "!" << "\033[0m" << std::endl;

    this->ClapTrap::_name = (name + "_clap_name");
    this->FragTrap::_hit_points = FragTrap::_hit_points;
    this->FragTrap::_attack_damage = FragTrap::_attack_damage;

    this->ScavTrap::_energy_points = ScavTrap::_energy_points;
}

DiamondTrap::DiamondTrap(const DiamondTrap& a) {
    *this = a;
}

DiamondTrap::~DiamondTrap(void) {
    std::cout << "\033[33m" << "DiamondTrap " << this->_name << " has been destroyed." << "\033[0m" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& a) {
    if (this !=  &a) {
        this->_name = a._name;
        this->FragTrap::_hit_points = a.FragTrap::_hit_points;
        this->FragTrap::_attack_damage = a.FragTrap::_attack_damage;
        this->ScavTrap::_energy_points = a.ScavTrap::_energy_points;
    }
    return *this;
}

void DiamondTrap::attack(const std::string& target) {
    this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
    std::cout << "\033[33m" << "My name is " << this->_name << "\033[0m" << std::endl;
    std::cout << "\033[33m" << "My ClapTrap name is " << this->ClapTrap::_name << "\033[0m" << std::endl;
}
