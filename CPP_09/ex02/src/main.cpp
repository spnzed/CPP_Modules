/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:18:31 by aaespino          #+#    #+#             */
/*   Updated: 2024/11/23 18:43:38 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

void algo(char **nums, int argc) {

    std::deque<int> dequeStack = getInp(nums, argc);
    int to_sort_size = dequeStack.size();

    clock_t	start;
	clock_t	end;

	printDeque( dequeStack, 1, "Before" );

	start = std::clock();
    msi(dequeStack, to_sort_size, 1);
	end = std::clock();

	double	dequeTime = static_cast< double >( end - start ) * 1000000 / CLOCKS_PER_SEC;
	printDeque( dequeStack, 1, "After" );

	std::cout << "Time to process a range of " << argc - 1 << " elements with std::[deque] : " << dequeTime << " us" << std::endl;
}

int main (int argc, char **argv) {
    if (argc <= 2) {
        std::cout << "Error: invalid input." << std::endl;
        return 1;
    } else {
        if (compArgs(argv, argc))
            algo(argv, argc);
    }
    return 0;
}
