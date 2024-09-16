/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:22:52 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/16 12:19:55 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"
#include <string>

Weapon::Weapon (std::string type) : _type(type) {
    std::cout << "Weapon " << type << " created" << std::endl;
}

Weapon::~Weapon (void) {
    std::cout << "Weapon " << this->_type << " destroyed" << std::endl;
}

std::string& Weapon::getType (void) {
    return this->_type;
}

void Weapon::setType (std::string type) {
    this->_type = type;
}
