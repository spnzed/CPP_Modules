/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:31:09 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/23 17:18:16 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"

Cure::Cure(void) {
}

Cure::Cure(const Cure &a) {
    *this->_type = a;    
}

Cure::Cure(std::string const & type) : _type(type) {   
}

Cure::~Cure(void) {
}

Cure Cure::operator=(const Cure &a) {
    if (this != &a) {
        this->_type = a._type;
    }
    return *this;
}

void Cure::use(ICharacter& target) const {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure* Cure::clone(void) const {
    Cure *ret = new Cure(this.getName());
    return ret;
}
