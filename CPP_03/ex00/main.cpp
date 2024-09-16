/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/08 18:04:12 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

int	main()
{
	ClapTrap	r("ffornes-");
	ClapTrap	h("aaespino");

	std::cout << std::endl;
	r.attack("aaespino");
	h.takeDamage(r.getAttack());
	std::cout << std::endl;
	h.beRepaired(5);
	std::cout << std::endl;
	h.attack("ffornes-");
	r.takeDamage(h.getAttack());
	std::cout << std::endl;
	r.beRepaired(5);
	std::cout << std::endl;
	h.attack("ffornes-");
	r.takeDamage(h.getAttack());
	std::cout << std::endl;
	r.attack("aaespino");
	h.takeDamage(r.getAttack());
	std::cout << std::endl;
	
	return (0);
}
