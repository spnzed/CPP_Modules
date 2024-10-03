/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:25:41 by aaespino          #+#    #+#             */
/*   Updated: 2024/10/03 13:05:41 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

template <typename T>
int easyfind(T container, int n) {

	typename T::iterator it = std::find(container.begin(), container.end(), n);

    if (it == container.end()) {
        throw std::out_of_range("Value not found in container");
    }

	return *it;
	
}

#endif
