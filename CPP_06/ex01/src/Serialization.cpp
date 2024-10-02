/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:07:26 by aaespino          #+#    #+#             */
/*   Updated: 2024/10/02 14:48:28 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serialization.hpp"

uintptr_t Serialization::serialize(Data* ptr) {

    uintptr_t ex = reinterpret_cast<uintptr_t>(ptr);

    return ex;
}

Data* Serialization::deserialize(uintptr_t raw) {

    Data* ex = reinterpret_cast<Data *>(raw);

    return ex;  
}

    