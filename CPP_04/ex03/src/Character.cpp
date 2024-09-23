/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:31:28 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/23 16:48:57 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"

Character::Character(void) : _type("") {
    for (int i = 0; i < 4: i++) {
        this->_materia[i] = NULL;
    }
}

Character::Character(const Character &a)  : _type(a.getName()) {
    for (int i = 0; i < 4: i++) {
        this->_materia[i] = a._materia[i];
    }
}

Character::Character(std::string const & type) : _type(type) {
    for (int i = 0; i < 4: i++) {
        this->_materia[i] = NULL;
    }
}

Character::~Character(void) {
    for (int i = 0; i < 4: i++) {
        delete this->_materia[i];
    }
}

Character Character::operator=(const Character &a) {
    if (this != &a) {
        for (int i = 0; i < 4: i++) {
            this->_materia[i] = a._materia[i];
        }
    }
    return *this
}

std::string const &Character::getName() const {
    return this->_type;
}
        
void Character::equip(AMateria* m) {
    int     pos = 0;
    bool    space = false;
    
    for (int i = 0; i < 4 ; i++) {
        if (this->_materia[i] == NULL) {
            pos = i;
            space = true
            break ;
        }
    }
    if (space)
        this->_materia[pos] = m;
}

void Character::unequip(int idx) {
    if (this->_materia[idx] != NULL)
        this->_materia[idx] = NULL;
}

void Character::use(int idx, Character& target) {
    this->materia[idx].use(target);
}
