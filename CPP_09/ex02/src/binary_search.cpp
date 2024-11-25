/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:19:24 by aaespino          #+#    #+#             */
/*   Updated: 2024/11/25 17:29:17 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

static int	getIndex( double index, size_t groupSize ) {
	return ( index - 1 ) * groupSize + groupSize - 1;
}

// int littleBinarySearch(const std::deque<int>& chain, int end, int value) {
//     int low = 0;
//     int high = end;
//     int index = 0;

//     // int count = 0;

//     while (low < high) {
//         // count++;
//         int mid = (low + high) / 2;
//         if (value > chain[mid]) {
//             low = mid + 1;
//         } else {
//             if (mid > low)
//                 high = mid - 1;
//             else
//                 high = low;
//         }
//     }

//     // count++;
//     if ( value < chain[ getIndex( low, 1 ) ] ) {
//         std::cout << "ARRIBA" << std::endl;
//         index = getIndex( low, 1 );
//     } else {
//         std::cout << "ABAJO" << std::endl;
//         index = getIndex( high, 1 ) + 1;
//     }

//     // std::cout << "Count: [little]" << count << std::endl;

//     return index;
// }

int binarySearch(const std::deque<int>& chain, int end, int value, int size) {
    
    int low = 1;
    int high = end;
    int index = 0;

    // int count = 0;

    while (low < high) {

        // count++;

        int mid = (high - low) / 2 + low;
    
        if (value > chain[getIndex( mid, size )]) {
            if (mid < high)
                low = mid + 1;
        } else {
            if (mid > low)
                high = mid - 1;
            else
                high = low;
        }
    }

    // count++;
    if ( value < chain[ getIndex( low, size ) ] ) {
        index = getIndex( low, size ) - size + 1;
    } else {
        index = getIndex( high, size ) + 1;
    }

    // std::cout << "Count: [big]" << count << std::endl;

    return index;
}
