/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/18 12:57:33 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"
#include <iostream>
#include <string>

int main() {
    ClapTrap clap("Clappy");
    ScavTrap scrav("Scravy");
    FragTrap frag("Fraggy");

    std::cout << std::endl;

    // Interacción entre ClapTrap y ScavTrap
    clap.attack(scrav.getName());
    scrav.takeDamage(clap.getAttackDamage());
    std::cout << std::endl;

    scrav.beRepaired(5);
    std::cout << std::endl;

    scrav.attack(clap.getName());
    clap.takeDamage(scrav.getAttackDamage());
    std::cout << std::endl;

	scrav.guardGate();
    std::cout << std::endl;

    // Interacción entre ScavTrap y FragTrap
    frag.attack(scrav.getName());
    scrav.takeDamage(frag.getAttackDamage());
    std::cout << std::endl;

    frag.highFivesGuys();
    std::cout << std::endl;

    // Interacción entre FragTrap y ClapTrap
    frag.attack(clap.getName());
    clap.takeDamage(frag.getAttackDamage());
    std::cout << std::endl;

    clap.beRepaired(3);
    std::cout << std::endl;

    return 0;
}
