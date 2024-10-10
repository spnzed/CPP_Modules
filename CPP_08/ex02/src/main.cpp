/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:05:13 by aaespino          #+#    #+#             */
/*   Updated: 2024/10/10 18:39:09 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MutantStack.hpp"

#include <iostream>

// Definición de colores
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

int main() {
    // Test 1: Push and Top
    {
        MutantStack<int> mstack;
        std::cout << GREEN << "Test 1: Push and Top" << RESET << std::endl;

        mstack.push(5);
        mstack.push(17);
        std::cout << "Top element: " << mstack.top() << std::endl; // Debería imprimir 17
    }

    // Test 2: Pop and Size
    {
        MutantStack<int> mstack;
        std::cout << BLUE << "Test 2: Pop and Size" << RESET << std::endl;

        mstack.push(5);
        mstack.push(17);
        mstack.pop();
        std::cout << "Stack size after pop: " << mstack.size() << std::endl; // Debería imprimir 1
    }

    // Test 3: Iterator
    {
        MutantStack<int> mstack;
        std::cout << MAGENTA << "Test 3: Iterator" << RESET << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;

        std::cout << "Stack contents: ";
        while (it != ite) {
            std::cout << *it << "; ";
            ++it;
        }
        std::cout << std::endl;
    }

    // Test 4: Copy Constructor
    {
        MutantStack<int> mstack;
        mstack.push(1);
        mstack.push(2);
        mstack.push(3);

        std::cout << CYAN << "Test 4: Copy Constructor" << RESET << std::endl;
        MutantStack<int> copyStack(mstack);
        std::cout << "Copy stack top element: " << copyStack.top() << std::endl; // Debería imprimir 3
    }

    // Test 5: Complete Stack Operations
    {
        MutantStack<int> mstack;
        std::cout << YELLOW << "Test 5: Complete Stack Operations" << RESET << std::endl;

        mstack.push(5);
        mstack.push(17);
        std::cout << "Top element: " << mstack.top() << std::endl; // Debería imprimir 17
        mstack.pop();
        std::cout << "Stack size after pop: " << mstack.size() << std::endl; // Debería imprimir 1
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;

        std::cout << "Stack contents: ";
        while (it != ite) {
            std::cout << *it << "; ";
            ++it;
        }
        std::cout << std::endl;

        std::stack<int> s(mstack);
    }

    return 0;
}
