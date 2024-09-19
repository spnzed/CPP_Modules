/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/19 14:44:01 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

#include <iostream>
#include <string>

int	main()
{
	ScavTrap	named("Scavy");
	ScavTrap	unnamed;

	std::cout << std::endl;
	named.attack(unnamed.getName());
	unnamed.takeDamage(named.getAttackDamage());
	std::cout << std::endl;
	unnamed.beRepaired(5);
	std::cout << std::endl;
	unnamed.attack(named.getName());
	named.takeDamage(unnamed.getAttackDamage());
	std::cout << std::endl;
	named.beRepaired(5);
	std::cout << std::endl;
	unnamed.attack(named.getName());
	named.takeDamage(unnamed.getAttackDamage());
	std::cout << std::endl;
	named.attack(unnamed.getName());
	unnamed.takeDamage(named.getAttackDamage());
	std::cout << std::endl;

	named.guardGate();
	unnamed.guardGate();
	std::cout << std::endl;

	return (0);
}
