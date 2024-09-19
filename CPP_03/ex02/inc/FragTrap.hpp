/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:22 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/19 16:49:08 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "../inc/ScavTrap.hpp"

#include <string>
#include <iostream>

class FragTrap : public ClapTrap {

    public:

        FragTrap(void);
        FragTrap(std::string name);
        FragTrap(const FragTrap& a);
        ~FragTrap(void);
        FragTrap &operator=(const FragTrap& a);

        void    highFivesGuys(void);
};

#endif
