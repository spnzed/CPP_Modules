/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:06:26 by aaespino          #+#    #+#             */
/*   Updated: 2024/10/11 13:57:05 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container> {
    public:
        MutantStack(void);
        MutantStack(const MutantStack &a);
        ~MutantStack(void);
        MutantStack &operator=(const MutantStack &a);

        typedef typename std::stack<T, Container>::container_type::iterator iterator; // Usar el iterador subyacente

        iterator begin() { return this->c.begin(); } // Acceso al contenedor subyacente
        iterator end() { return this->c.end(); }
};

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(void) : std::stack<T, Container>() {
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack &a) : std::stack<T, Container>() {
    *this = a;
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack(void) {
}

template <typename T, typename Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(const MutantStack<T, Container> &a) {
    std::stack<T, Container>::operator=(a);
    return *this;
}

#endif