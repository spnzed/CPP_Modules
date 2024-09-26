/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/26 16:07:07 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"
#include <iostream>
#include <string>

Brain::Brain (void) {
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain (const Brain &a) {
    std::cout << "Brain copy constructor called" << std::endl;
    *this = a;
    for (int i = 0; i < 100; i++) {
        this->_ideas[i] = a._ideas[i];
    }
}

Brain::~Brain (void) {
    std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain &a) {
    std::cout << "Brain copy assignment called" << std::endl;
    if (this != &a) {
        for (int i = 0; i < 100; i++) {
            this->_ideas[i] = a._ideas[i];
        }
    }
    return *this;
}
