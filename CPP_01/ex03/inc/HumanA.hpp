/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:18:55 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/14 16:39:27 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA {
    public:
        HumanA (std::string name, Weapon &weapon);
        ~HumanA (void);
        void attack(void);

    private:
        std::string _name;
        Weapon &_weapon;
};
