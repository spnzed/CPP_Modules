/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:22 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/08 18:12:43 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

    public:

        FragTrap(std::string name);
        FragTrap(void);
        ~FragTrap(void);

        void    highFivesGuys(void);
};

