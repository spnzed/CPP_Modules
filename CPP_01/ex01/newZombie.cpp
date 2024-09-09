/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:37:02 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/01 22:52:59 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"
using namespace std;

Zombie *newZombie ( string name) {
    Zombie *zombie = new Zombie;
    
    zombie[0].setName(name);
    return zombie;
}
