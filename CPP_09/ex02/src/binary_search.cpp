/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:19:24 by aaespino          #+#    #+#             */
/*   Updated: 2024/11/20 18:39:45 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

static int	getIndex( double index, size_t groupSize ) {
	return ( index - 1 ) * groupSize + groupSize - 1;
}

int binarySearch(const std::deque<int>& chain, int end, int value, int size) {
    int low = 0;
    int high = end;

    int count = 0;
    int index = 0;

    std::cout << value << std::endl; 

    while (low < high) {

        int mid = (high - low) / 2 + low;
    
        if (value > chain[getIndex( mid, size )]) {
            if (mid < high)
                low = mid + 1;
            else
                low = mid;
        }
        else {
            if (mid > low)
                high = mid + 1;
            else
                high = low;
        }

    }
    count++;

    if ( value < chain[ getIndex( low, size ) ] ) {
        index = getIndex( low, size ) - size + 1;
    } else {
        index = getIndex( high, size ) + 1;
    }

    return index;
}
