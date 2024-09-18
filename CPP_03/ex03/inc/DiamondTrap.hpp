/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:03:24 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/18 18:08:02 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap {
    public:
        DiamondTrap(void);
        DiamondTrap(std::string name);
        DiamondTrap(const &DiamondTrap a);
        ~DiamondTrap(void);
        DiamondTrap &operator=(const &DiamondTrap a);

        ScavTrap::attack();
        void    whoAmI(void);
    private:
        std::string _name;
};
