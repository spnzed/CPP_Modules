/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:22:52 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/07 23:32:43 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
using namespace std;

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:22:52 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/07 23:27:55 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
using namespace std;

Weapon::Weapon (string type) {
    setType(type);
}

Weapon::~Weapon (void) {}

string Weapon::getType (void) {
    return this->_type;
}

void Weapon::setType (string type) {
    this->_type = type;
}