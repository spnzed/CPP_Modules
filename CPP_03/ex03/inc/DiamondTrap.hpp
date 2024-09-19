/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:03:24 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/19 16:49:08 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "../inc/FragTrap.hpp"

#include <iostream>
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap {
    public:
        DiamondTrap(void);
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& a);
        
        ~DiamondTrap(void);
        
        DiamondTrap &operator=(const DiamondTrap& a);

        void    attack(const std::string& target);
        void    whoAmI(void);

    private:
        std::string _name;
};

#endif
