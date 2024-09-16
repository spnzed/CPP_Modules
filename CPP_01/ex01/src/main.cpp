/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 22:30:29 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/16 13:02:35 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/Zombie.hpp"

int main (void) {
    Zombie *zombie = newZombie("pepe");
    int N = 10;

    zombie->announce();
    randomChump("luis");

    Zombie *horde = zombieHorde(N, "oscar");

    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }

    delete[] horde;
    delete zombie;
}
