/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/26 15:54:40 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"

#include <iostream>
#include <string>

int main() {
    int     N = 10;
    const   Animal* Farm[10];

    if (N % 2 == 0) {    
        for (int i = 0; i < N / 2; i++) {
            std::cout << "\033[34m" << "Creating Dog Number " << i + 1 << "\033[0m" << std::endl;
            Farm[i] = new Dog();
        }
        for (int i = N / 2; i < N; i++) {
            std::cout << "\033[33m" << "Creating Cat Number " << i + 1 << "\033[0m" << std::endl;
            Farm[i] = new Cat();
        }
        for (int i = 0; i < N; i++) {
            std::cout << "\033[31m" << "Deleting animal Number " << i + 1 << "\033[0m" << std::endl;
            delete Farm[i];
        }
    } else {
        std::cout << "Error. Odd numbers are not allowed." << std::endl;
    }

    std::cout << std::endl;
    std::cout << "\033[30m" << "Should not create a leak. ↓↓↓↓" << "\033[0m" << std::endl;

    const Animal *i = new Dog();
    const Animal *j = new Cat();

    delete i;
    delete j;

    return 0;
}
