/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:25:25 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/25 12:13:28 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
    for (int i = 0; i < 4; i++) {
        this->_materia[i] = NULL;
    }
    std::cout << "\033[33;4m" << "[MateriaSource]\t\t" << "\033[0;4m" << "default constructor called" << "\033[0m" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &a) {
    *this = a;
    std::cout << "\033[33;4m" << "[MateriaSource]\t\t" << "\033[0;4m" << "copy constructor called" << "\033[0m" << std::endl;
}

MateriaSource::~MateriaSource(void) {
    for (int i = 0; i < 4; i++) {
        if (this->_materia[i] != NULL)
            delete this->_materia[i];
        this->_materia[i] = NULL;
    }
    std::cout << "\033[33;4m" << "[MateriaSource]\t\t" << "\033[0;4m" << "destructor called" << "\033[0m" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &a) {
    if (this != &a) {
        for (int i = 0; i < 4; i++) {
            if (this->_materia[i] != NULL)
                delete this->_materia[i];
        }
        for (int i = 0; i < 4; i++) {
            if (a._materia[i] != NULL) {
                this->_materia[i] = a._materia[i]->clone();
            }
            else
                this->_materia[i] = NULL;
        }
    }
    std::cout << "\033[33;4m" << "[MateriaSource]\t\t" << "\033[0;4m" << "assignment operator called" << "\033[0m" << std::endl;
    return (*this);
}

void MateriaSource::learnMateria(AMateria* materia) {
    if (!materia || materia->getName() == "Default_Materia") {
        std::cout << "Default Materia can't be learned" << std::endl;
        return ;
    }
    for (int i = 0; i < 4; i++) {
        if (this->_materia[i] == NULL) {
            this->_materia[i] = materia;
            std::cout << "Materia learned on slot " << i << " is from type " << this->_materia[i]->getName() << std::endl;
            return ;
        }
    }
    std::cout << "Materia " << materia->getName() << " can't be learned. No space available." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        // std::cout << "\033[32m" << type  << "\033[0m" << std::endl;
        // std::cout << "\033[32m" << i  << "\033[0m" << std::endl;
        // std::cout << "\033[32m" << this->_materia[i]->getName()  << "\033[0m" << std::endl;
        if (this->_materia[i] != NULL && this->_materia[i]->getName() == type && this->_materia[i]->getName() != "Default_Materia") {
            std::cout << "Created a materia with type " << type << std::endl;
            return (this->_materia[i]->clone());
        }
    }
    std::cout << "Materia " << type << " is not available" << std::endl;
    return 0;
}

void MateriaSource::printMaterias(void) {
    for(int i = 0; i < 4; i++)
	{
		if (this->_materia[i] != NULL)
			std::cout << "Materia saved on slot " << i << " is from type " << this->_materia[i]->getName() << std::endl;
		else
			std::cout << "No materia saved on slot " << i << std::endl;
	}
	std::cout << std::endl;
}
