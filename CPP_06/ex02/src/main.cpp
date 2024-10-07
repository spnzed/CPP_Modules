/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:02:33 by aaespino          #+#    #+#             */
/*   Updated: 2024/10/07 14:01:34 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"

#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

#include <cstdlib>
#include <ctime>

Base* generate(void) {

    Base *ret;

    int n;

    srand(static_cast<unsigned int>(time(NULL)));

    n = rand() % 3;

    switch (n) {
        case 0:
            ret = new A;
            break ;
        case 1:
            ret = new B;
            break ;
        case 2:
            ret = new C;
            break ;
    }
    return ret;
}

void identify(Base* p) {
    A* toA = dynamic_cast<A*>(p);
    if (toA) {
        std::cout << "A" << std::endl;
    } else {
        B* toB = dynamic_cast<B*>(p);
            if (toB) {
                std::cout << "B" << std::endl;
            } else {
                C* toC = dynamic_cast<C*>(p);
                if (toC) {
                      std::cout << "C" << std::endl;
                }
            }
    }
}

void identify(Base& p) {
    try {
        A& toA = dynamic_cast<A&>(p);
        (void)toA;
        std::cout << "A" << std::endl;
    } catch (std::exception) {
        try {
            B& toB = dynamic_cast<B&>(p);
            (void)toB;
            std::cout << "B" << std::endl;
        } catch (std::exception) {
                try {
                    C& toC = dynamic_cast<C&>(p);
                    (void)toC;
                    std::cout << "C" << std::endl;
                } catch (std::exception) {
                    std::cout << "Error" << std::endl;
                }
        }
    }
}

int main() {

    Base* obj = generate();

    identify(obj);
    identify(*obj);

    delete obj;

    return 0;
}
