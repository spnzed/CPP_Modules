/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/18 11:30:37 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"
#include <iostream>
#include <string>

int	main()
{
	ClapTrap	r("ffornes-");
	ClapTrap	h("aaespino");

	std::cout << std::endl;
	r.attack("aaespino");
	h.takeDamage(r.getAttackDamage());
	std::cout << std::endl;
	h.beRepaired(5);
	std::cout << std::endl;
	h.attack("ffornes-");
	r.takeDamage(h.getAttackDamage());
	std::cout << std::endl;
	r.beRepaired(5);
	std::cout << std::endl;
	h.attack("ffornes-");
	r.takeDamage(h.getAttackDamage());
	std::cout << std::endl;
	r.attack("aaespino");
	h.takeDamage(r.getAttackDamage());
	std::cout << std::endl;
	
	return (0);
}
