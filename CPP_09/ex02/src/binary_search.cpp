/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:19:24 by aaespino          #+#    #+#             */
/*   Updated: 2024/11/20 15:32:32 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

int binarySearch(const std::deque<int>& chain, int start, int end, int value) {
    int low = start;
    int high = end;

    while (low < high) {
        int mid = (low + high) / 2;
        if (chain[mid] <= value) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}
