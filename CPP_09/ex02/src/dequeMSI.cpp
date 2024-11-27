/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeMSI.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:16:09 by aaespino          #+#    #+#             */
/*   Updated: 2024/11/27 15:20:41 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

static void	pairSwap(std::deque< int >& src, int groupSize) {
	
	int	right = groupSize - 1;
	
	while (right + groupSize < int(src.size())) {
		std::deque< int >::iterator	first = src.begin();
		std::advance(first, right);
		std::deque< int >::iterator	second = src.begin();
		std::advance(second, right + groupSize);
		
		if (*first > *second) {
			std::deque< int >::iterator	trueFirst = src.begin();
			std::advance(trueFirst, right - groupSize + 1);
			std::deque< int >::iterator	trueSecond = src.begin();
			std::advance(trueSecond, right + 1);
			std::advance(first, 1);
			std::swap_ranges(trueFirst, first, trueSecond); 
		}
		right += groupSize * 2;
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
