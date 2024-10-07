/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:07:26 by aaespino          #+#    #+#             */
/*   Updated: 2024/10/07 13:39:06 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serialization.hpp"

Serialization::Serialization(void) {
}

Serialization::Serialization(const Serialization& a) {
    *this = a;
}

Serialization::~Serialization(void) {
}

Serialization &Serialization::operator=(const Serialization& a) {
    if (this != &a) {
    }
    return *this;
}

uintptr_t Serialization::serialize(Data* ptr) {

    uintptr_t ex = reinterpret_cast<uintptr_t>(ptr);

    return ex;
}

Data* Serialization::deserialize(uintptr_t raw) {

    Data* ex = reinterpret_cast<Data *>(raw);

    return ex;  
}
