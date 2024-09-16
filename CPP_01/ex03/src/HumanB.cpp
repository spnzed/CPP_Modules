/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:28:05 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/14 16:38:53 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"
#include <string>

HumanB::HumanB (std::string name) : _name(name), _weapon(NULL) {
    std::cout << "The HumanB ";
    std::cout << this->_name;
    std::cout << " is created without weapon";
    std::cout << std::endl;
    _weapon = NULL;
}

HumanB::~HumanB (void) {
    std::cout << "The HumanB " << this->_name;
    std::cout << " has been destroyed" << std::endl;
}

void HumanB::setWeapon (Weapon &weapon) {
    this->_weapon = &weapon;
    std::cout << this->_name;
    std::cout << " is armed with " << weapon.getType();
    std::cout << std::endl;
}

void HumanB::attack (void) {
    if (this->_weapon != NULL)
    {
        std::cout << this->_name;
        std::cout << " attacks with his " << this->_weapon->getType();
        std::cout << std::endl;
    }
    else
    {
        std::cout << this->_name;
        std::cout << " doesn't have a weapon";
        std::cout << std::endl;
    }
}
