/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:30:50 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/23 18:27:54 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"

AMateria::AMateria(void) {
}

AMateria::AMateria(const AMateria &a) {
    *this = a;
}

AMateria::AMateria(std::string const & type) : _type(type) {
}

AMateria::~AMateria(void) {
}

AMateria& AMateria::operator=(const AMateria &a) {
    if (this != &a) {
        this->_type = a._type;
    }
    return *this;
}

std::string const & AMateria::getName(void) const {
    return this->_type;
}

void AMateria::use(ICharacter& target) {
    (void)target;
}
