/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:07:45 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/13 17:35:00 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie {

    public:
        Zombie( std::string name );
        ~Zombie( void );
        void announce( void );
    private:
        std::string _name;
};

Zombie *newZombie( std::string name );
void randomChump( std::string name );

#endif
