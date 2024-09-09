/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 22:30:29 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/01 22:32:15 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int main (void) {
    Zombie *zombie = newZombie("pepe");
    zombie->announce();
    randomChump("luis");
    delete zombie;
}