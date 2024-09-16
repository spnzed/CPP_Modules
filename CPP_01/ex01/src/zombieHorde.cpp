/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 22:37:02 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/13 17:37:51 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/Zombie.hpp"
#include <string>

Zombie  *zombieHorde( int N, std::string name ) {
    Zombie   *Horde = new Zombie[N];

    for (int i = 0; i < N; i++) {
        Horde[i].setName(name);
    }
    return Horde;
}
