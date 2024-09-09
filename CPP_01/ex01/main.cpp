/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 22:30:29 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/01 23:03:47 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int main (void) {
    Zombie *zombie = newZombie("pepe");
    zombie->announce();
    randomChump("luis");

    Zombie *horde = zombieHorde(5, "oscar");

    for (int i = 0; i < 5; i++) {
        horde[i].announce();
    }

    delete[] horde;
    delete zombie;
}
