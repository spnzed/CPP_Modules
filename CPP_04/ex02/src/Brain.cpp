/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/19 13:12:13 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"
#include <iostream>
#include <string>

Brain::Brain (void) {
    std::cout << "Brain Constructor Called" << std::endl;
}

Brain::Brain (const Brain &a) {
    *this = a;
}

Brain::~Brain (void) {
    std::cout << "Brain Destructor Called" << std::endl;
}

Brain& Brain::operator=(const Brain &a) {
    if (this != &a) {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = a.ideas[i];
        }
    }
    return *this;
}