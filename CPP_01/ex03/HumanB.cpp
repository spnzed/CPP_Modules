/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:28:05 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/08 00:19:11 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
using namespace std;

HumanB::HumanB (string name) : _name(name) {
    cout << "The HumanB ";
    cout << this->_name;
    cout << " is created without weapon";
    cout << endl;
    _weapon = NULL;
}

HumanB::~HumanB (void) {
    cout << "The HumanB " << this->_name;
    cout << " has been destroyed" << endl;
}

void HumanB::setWeapon (Weapon weapon) {
    this->_weapon = &weapon;
    cout << this->_name;
    cout << " is armed with " << weapon.getType();
    cout << endl;
}

void HumanB::attack (void) {
    if (this->_weapon != NULL)
    {
        cout << this->_name;
        cout << " attacks with their " << this->_weapon->getType();
        cout << endl;
    }
    else
    {
        cout << this->_name;
        cout << " doesn't have a weapon";
        cout << endl;
    }
}
