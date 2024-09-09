/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:18:55 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/02 00:19:08 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB {
    public:
        HumanB (std::string name);
        ~HumanB (void);
        void attack(void);
        void setWeapon(Weapon weapon);
    private:
        std::string _name;
        Weapon *_weapon;
};