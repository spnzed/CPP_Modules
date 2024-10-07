/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:50:43 by aaespino          #+#    #+#             */
/*   Updated: 2024/10/07 13:38:12 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#pragma once

#include <iostream>
#include <string>
#include <stdint.h>

struct Data {
    int num;
};

class Serialization {
    public:
        Serialization(void);
        Serialization(const Serialization& a);
        ~Serialization(void);
        Serialization &operator=(const Serialization& a);

        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif
