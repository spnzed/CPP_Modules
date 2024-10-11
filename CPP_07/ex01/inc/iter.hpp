/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:44:00 by aaespino          #+#    #+#             */
/*   Updated: 2024/10/11 18:01:56 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void iter(T* address, size_t len, void (*func)(T&))
{
    for (size_t i = 0; i < len ; i++) {
        func(address[i]);
    }
}

template <typename T>
void iter(T* address, size_t len, void (*func)(const T&))
{
    for (size_t i = 0; i < len ; i++) {
        func(address[i]);
    }
}

template < typename T >
void print(const T& value) {
    std::cout << value << " ";
}

#endif
