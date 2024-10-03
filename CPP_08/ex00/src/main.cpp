/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:32:11 by aaespino          #+#    #+#             */
/*   Updated: 2024/10/03 12:59:03 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"

int main () {
    
    std::vector<int> innerVector;
    
    innerVector.push_back(1);
    innerVector.push_back(2);
    innerVector.push_back(3);
    innerVector.push_back(4);
    
    try {
        std::cout << easyfind(innerVector, 7) << std::endl;
    } catch (std::out_of_range& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
