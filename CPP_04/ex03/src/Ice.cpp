/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:31:21 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/23 17:17:33 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ice.hpp"

Ice::Ice(void) {
}

Ice::Ice(const Ice &a) {
    *this->_type = a;    
}

Ice::Ice(std::string const & type) : _type(type) {
}

Ice::~Ice(void) {
}

Ice Ice::operator=(const Ice &a) {
    if (this != &a) {
        this->_type = a._type;
    }
    return *this;
}

void Ice::use(ICharacter& target) const {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice* Ice::clone(void) const {
    Ice *ret = new Ice(this.getName());
    return ret;
}
