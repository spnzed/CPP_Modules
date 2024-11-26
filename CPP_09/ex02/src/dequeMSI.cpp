/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeMSI.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:16:09 by aaespino          #+#    #+#             */
/*   Updated: 2024/11/25 19:49:39 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

static void	pairSwap( std::deque< int >& src, size_t groupSize ) {
	size_t	tail = groupSize - 1;

	while ( tail + groupSize < src.size() ) {
		std::deque< int >::iterator	first = src.begin() + tail;
		std::deque< int >::iterator	second = src.begin() + tail + groupSize;

		if ( *first > *second )
			std::swap_ranges( first - groupSize + 1, first + 1, second - groupSize + 1);
		tail += groupSize * 2;
	}
}

void msi(std::deque<int>& stack, int end, int size) {

    if (size > end)
        return;

    int actual_end = end;

    if (end % 2 != 0)
        end -= size;

    // 1. Pair swapping
    pairSwap(stack, size);

    // 2. Rec
    msi(stack, end, size * 2);

    // 3. Jacob
    if (stack.size() / size > 2)
        insertWithJacobsthal(stack, actual_end, size);
}
