/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:22 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/19 12:29:02 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

#include <string>
#include <iostream>

class FragTrap : virtual public ClapTrap {

    public:

        FragTrap(void);
        FragTrap(std::string name);
        FragTrap(const FragTrap& a);
        ~FragTrap(void);
        FragTrap &operator=(const FragTrap& a);

        void    highFivesGuys(void);
};

