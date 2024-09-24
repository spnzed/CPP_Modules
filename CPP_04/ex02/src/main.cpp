/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/20 14:38:39 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"

#include <iostream>
#include <string>

int main() {

    std::cout << "Constructors: " << std::endl;
    std::cout << std::endl;

    // const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << std::endl;

    std::cout << "Classes: " << std::endl;
    std::cout << std::endl;

    // std::cout << "\033[35m" << meta->getType() << "\033[0m" << " " << std::endl;
    std::cout << "\033[34m" << j->getType() << "\033[0m" << " " << std::endl;
    std::cout << "\033[32m" << i->getType() << "\033[0m" << " " << std::endl;

    std::cout << std::endl;
    std::cout << "Sounds: " << std::endl;
    std::cout << std::endl;

    // std::cout << "\033[35m";
    // meta->makeSound();
    // std::cout << "\033[0m"; 

    std::cout << "\033[34m";
    j->makeSound();
    std::cout << "\033[0m"; 

    std::cout << "\033[32m";
    i->makeSound();
    std::cout << "\033[0m"; 

    std::cout << std::endl;

    std::cout << "Destructors: " << std::endl;
    std::cout << std::endl;

    // delete meta;
    delete i;
    delete j;

    return 0;
}
