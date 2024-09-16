/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:18:55 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/14 16:39:31 by aaespino         ###   ########.fr       */
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
        void setWeapon(Weapon &weapon);

    private:
        std::string _name;
        Weapon *_weapon;
};
