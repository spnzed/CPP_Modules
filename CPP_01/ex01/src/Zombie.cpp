/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:18:22 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/16 13:02:03 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/Zombie.hpp"

Zombie::Zombie( void ) {
    std::cout << "Default_Zombie : Resurrected" << std::endl;
}

Zombie::Zombie( std::string name ) {
    this->_name = name;
    std::cout << name << ": Resurrected" << std::endl;
}

Zombie::~Zombie( void ) {
    std::cout << this->_name;
    std::cout << ": Was destroyed" << std::endl;
}

void    Zombie::announce ( void ) {
    std::cout << this->_name;
    std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

bool    Zombie::setName ( std::string name ) {
    this->_name = name;
    return true;
}
