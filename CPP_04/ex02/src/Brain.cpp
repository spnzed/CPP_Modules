/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/20 12:50:58 by aaronespino      ###   ########.fr       */
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
