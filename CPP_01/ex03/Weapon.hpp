/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:18:55 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/07 23:28:57 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP

# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {
    public:
        Weapon (std::string type);
        ~Weapon (void);
        std::string getType( void );
        void setType( std::string type );
    private:
        std::string _type;
};

#endif