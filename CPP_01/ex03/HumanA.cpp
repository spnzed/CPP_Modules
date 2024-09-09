/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:28:05 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/08 00:19:26 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
using namespace std;

HumanA::HumanA (string name, Weapon weapon) : _name(name), _weapon(weapon) {
    cout << "The HumanA ";
    cout << this->_name;
    cout << " is created with a weapon";
    cout << endl;
    setWeapon(weapon);
}

HumanA::~HumanA (void) {
    cout << "The HumanA " << this->_name;
    cout << " has been destroyed" << endl;
}

void HumanA::setWeapon (Weapon weapon) {
    cout << this->_name;
    cout << " is armed with " << weapon.getType();
    cout << endl;
}

void HumanA::attack (void) {
    cout << this->_name;
    cout << " attacks with their " << this->_weapon.getType();
    cout << endl;
}
