/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:28:05 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/14 16:37:32 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanA.hpp"
#include <string>

HumanA::HumanA (std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {
    std::cout << "The HumanA ";
    std::cout << this->_name;
    std::cout << " is created with a weapon";
    std::cout << std::endl;
}

HumanA::~HumanA (void) {
    std::cout << "The HumanA " << this->_name;
    std::cout << " has been destroyed" << std::endl;
}

void HumanA::attack (void) {
    std::cout << this->_name;
    std::cout << " attacks with his " << this->_weapon.getType();
    std::cout << std::endl;
}
