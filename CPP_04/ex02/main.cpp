/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/12 11:16:02 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>
#include <string>

int main() {
    const Animal* Farm[10];

    for (int i = 0; i < 5 ; i++) {
        Farm[i] = new Dog();
    }

    for (int i = 5; i < 10 ; i++) {
        Farm[i] = new Cat();
    }

    for (int i = 0; i < 10 ; i++) {
        delete Farm[i];
    }

    return 0;
}