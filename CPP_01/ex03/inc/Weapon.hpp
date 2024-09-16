/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:18:55 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/14 16:36:02 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP

# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {
    private:
        std::string _type;
    public:
        Weapon (std::string type);
        ~Weapon (void);

        std::string& getType( void );
        void setType( std::string type );
};

#endif
