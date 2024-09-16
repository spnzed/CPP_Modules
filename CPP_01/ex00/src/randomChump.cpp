/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:37:02 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/13 17:34:49 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/Zombie.hpp"
#include <string>

void randomChump ( std::string name ) {
    Zombie  zombie(name);
    zombie.announce();
    //newZombie(name)->announce();
}
