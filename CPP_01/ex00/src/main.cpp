/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 22:30:29 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/14 15:53:44 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/Zombie.hpp"

int main (void) {
    Zombie *zombie = newZombie("pepe");

    zombie->announce();
    randomChump("luis");
    delete zombie;
}
