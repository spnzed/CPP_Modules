/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:22 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/08 18:12:43 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

        ClapTrap(std::string name);
        ClapTrap(void);
        ~ClapTrap(void);

        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);

        int             getAttack(void);
        std::string     getName(void);
};
