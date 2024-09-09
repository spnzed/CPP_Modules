/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 22:37:02 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/01 23:00:40 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

using namespace std;

Zombie  *zombieHorde( int N, string name ) {
    Zombie   *Horde = new Zombie[N];

    for (int i = 0; i < N; i++) {
        Horde[i].setName(name);
    }
    return Horde;
}
