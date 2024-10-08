/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:22 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/19 16:49:08 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
    private:
    protected:

        std::string _name;

        int         _hit_points;
        int         _energy_points;
        int         _attack_damage;

    public:

        ClapTrap(void);
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& a);
        ~ClapTrap(void);
        ClapTrap &operator=(const ClapTrap& a);

        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);

        std::string getName(void) const;
        int         getHitPoints(void);
        int         getEnergyPoints(void);
        int         getAttackDamage(void);
};

#endif
