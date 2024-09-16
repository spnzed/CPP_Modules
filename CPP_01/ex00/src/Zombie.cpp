/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:18:22 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/14 15:56:30 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/Zombie.hpp"
#include <string>

Zombie::Zombie( std::string name ) {
    this->_name = name;
    std::cout << name << ": Resurrected" << std::endl;
}

Zombie::~Zombie( void ) {
    std::cout << this->_name << ": Was destroyed" << std::endl;
}

void    Zombie::announce ( void ) {
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
