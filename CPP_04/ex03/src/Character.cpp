/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:31:28 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/25 17:39:44 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"

Character::Character(void) : _type("Default_Character") {
    for (int i = 0; i < 4; i++) {
        this->_materia[i] = NULL;
    }
    std::cout << "\033[32m" << "[Character]\t" << "\033[0;4m" << "default constructor called" << "\033[0m" << std::endl;
}

Character::Character(Character const &a)  : _type(a.getName()) {
    for (int i = 0; i < 4; i++) {
        this->_materia[i] = NULL;
    }
    *this = a;
    if (a.getName().length() <= 3)
        std::cout << "\033[32m" << "[Character " << a.getName() << "]\t\t" << "\033[0;4m" << "copy constructor called" << "\033[0m" << std::endl;
    else
        std::cout << "\033[32m" << "[Character " << a.getName() << "]\t" << "\033[0;4m" << "copy constructor called" << "\033[0m" << std::endl;
}

Character::Character(std::string const & type) : _type(type) {
    for (int i = 0; i < 4; i++) {
        this->_materia[i] = NULL;
    }
    if (type.length() <= 3)
        std::cout << "\033[32m" << "[Character " << type << "]\t\t" << "\033[0;4m" << "parameterized constructor called" << "\033[0m" << std::endl;
    else
        std::cout << "\033[32m" << "[Character " << type << "]\t" << "\033[0;4m" << "parameterized constructor called" << "\033[0m" << std::endl;
}

Character::~Character(void) {
    for (int i = 0; i < 4; i++) {
        if (this->_materia[i] != NULL) {
            delete this->_materia[i];
        }
    }
    if (this->_type.length() <= 3)
        std::cout << "\033[32m" << "[Character " << this->_type << "]\t\t" << "\033[0;4m" << "destructor called" << "\033[0m" << std::endl;
    else
        std::cout << "\033[32m" << "[Character " << this->_type << "]\t" << "\033[0;4m" << "destructor called" << "\033[0m" << std::endl;
}

Character &Character::operator=(const Character &a) {
    if (this != &a) {
        for (int i = 0; i < 4; i++) {
            if (this->_materia[i] != NULL)
               delete this->_materia[i];
            this->_materia[i] = NULL;
        }
        for (int i = 0; i < 4; i++) {
            if (a._materia[i] != NULL)
                this->_materia[i] = a._materia[i]->clone();
        }
    }
    return *this;
    if (this->_type.length() <= 3)
        std::cout << "\033[32m" << "[Character " << this->_type << "]\t\t" << "\033[0;4m" << "assignment operator called" << "\033[0m" << std::endl;
    else
        std::cout << "\033[32m" << "[Character " << this->_type << "]\t" << "\033[0;4m" << "assignment operator called" << "\033[0m" << std::endl;
}

std::string const &Character::getName() const {
    return this->_type;
}
        
void Character::equip(AMateria* m) {
    for (int i = 0; i < 4 ; i++) {
        if (m && (this->_materia[i] == NULL)) {
            this->_materia[i] = m->clone();
            std::cout << "Materia equiped on slot " << i << " is from type " << this->_materia[i]->getName() << std::endl;
            return ;
        }
        if (m && (this->_materia[i]->getName() == "unequipped")) {
            delete this->_materia[i];
            this->_materia[i] = m->clone();
            std::cout << "Materia equiped on slot " << i << " is from type " << this->_materia[i]->getName() << std::endl;
            return ;
        }
    }
    if (m)
        std::cout << "No space to equip more materia. " << this->_type << "'s inventory is full" << std::endl;
    else
        std::cout << "Invalid Materia is not equipable" << std::endl;
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && this->_materia[idx] != NULL && this->_materia[idx]->getName() != "unequipped") {
        std::cout << "Unequipped on slot " << idx << " is from type " << this->_materia[idx]->getName() << std::endl;
        this->_materia[idx]->setName("unequipped");
    }
    else if (idx < 0 || idx > 4 )
		std::cout << "Slot number " << idx << " is invalid!" << std::endl;
	else
		std::cout << "Slot number " << idx << " is empty!" << std::endl;
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && this->_materia[idx] != NULL && this->_materia[idx]->getName() != "unequipped")
        this->_materia[idx]->use(target);
    else if (idx < 0 || idx > 4 )
		std::cout << "Slot number " << idx << " is invalid!" << std::endl;
	else
		std::cout << "Slot number " << idx << " is empty!" << std::endl;
}

void Character::printMaterias(void) {
    for(int i = 0; i < 4; i++)
	{
		if (this->_materia[i] != NULL) {
            if (this->_materia[i]->getName() == "unequipped")
			    std::cout << "No materia saved on slot " << i << std::endl;
            else
			    std::cout << "Materia saved on slot " << i << " is from type " << this->_materia[i]->getName() << std::endl;
        }
		else
			std::cout << "No materia saved on slot " << i << std::endl;
	}
	std::cout << std::endl;
}
