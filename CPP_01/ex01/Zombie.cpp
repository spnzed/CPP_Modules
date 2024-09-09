/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:18:22 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/01 22:48:12 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
using namespace std;

Zombie::Zombie( void ) {

}

Zombie::~Zombie( void ) {
    cout << this->_name;
    cout << ": Was destroyed" << endl;
}

void    Zombie::announce ( void ) {
    cout << this->_name;
    cout << ": BraiiiiiiinnnzzzZ..." << endl;
}

bool    Zombie::setName ( string name ) {
    this->_name = name;
    return true;
}
