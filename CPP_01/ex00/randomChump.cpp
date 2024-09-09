/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:43:44 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/01 22:34:06 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
using namespace std;

void randomChump ( string name ) {
    // Zombie  chump = Zombie(name);
    // chump.announce();
    newZombie(name)->announce();
}
