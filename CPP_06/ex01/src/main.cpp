/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:21:54 by aaespino          #+#    #+#             */
/*   Updated: 2024/10/02 14:51:06 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serialization.hpp"

int main () {
    Data *example = new Data;

    example->num = 1;

    uintptr_t ex = Serialization::serialize(example);

    std::cout << "Serialized:\t0x" << std::hex << ex << std::endl;
    std::cout << "Deserialized:\t" << Serialization::deserialize(ex) << std::endl;
    std::cout << "Original:\t" << example << std::endl;

    delete example;

    return 0;
}
