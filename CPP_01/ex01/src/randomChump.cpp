/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:43:44 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/13 17:37:36 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/Zombie.hpp"
#include <string>

void randomChump ( std::string name ) {
    Zombie  zombie(name);
    zombie.announce();
    //newZombie(name)->announce();
}
