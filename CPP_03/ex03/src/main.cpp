/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/19 12:34:43 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"
#include <iostream>
#include <string>

int main() {
    DiamondTrap d("Travis");

	std::cout << std::endl;
	d.whoAmI();
	std::cout << std::endl;
	d.attack("nobody");
	std::cout << std::endl;
	d.guardGate();
	d.highFivesGuys();
	std::cout << std::endl;
	d.beRepaired(5);
	std::cout << std::endl;

    return 0;
}
