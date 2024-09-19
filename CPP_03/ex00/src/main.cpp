/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/19 13:36:25 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include <iostream>
#include <string>

int	main()
{
	ClapTrap	r("Clappy 1");
	ClapTrap	h("Clappy 2");

	std::cout << std::endl;
	r.attack("Clappy 2");
	h.takeDamage(r.getAttackDamage());
	std::cout << std::endl;
	h.beRepaired(5);
	std::cout << std::endl;
	h.attack("Clappy 1");
	r.takeDamage(h.getAttackDamage());
	std::cout << std::endl;
	r.beRepaired(5);
	std::cout << std::endl;
	h.attack("Clappy 1");
	r.takeDamage(h.getAttackDamage());
	std::cout << std::endl;
	r.attack("Clappy 2");
	h.takeDamage(r.getAttackDamage());
	std::cout << std::endl;

	return (0);
}
