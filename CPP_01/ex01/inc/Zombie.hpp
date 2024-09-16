/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:07:45 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/16 13:02:13 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie {

    public:
        Zombie( void );
        Zombie( std::string name );
        ~Zombie( void );
        void announce( void );
        bool setName( std::string name );
    private:
        std::string _name;
};

Zombie *newZombie( std::string name );
void randomChump( std::string name );
Zombie  *zombieHorde( int N, std::string name );

#endif
