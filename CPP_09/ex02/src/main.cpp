/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:18:31 by aaespino          #+#    #+#             */
/*   Updated: 2024/11/25 19:54:31 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

bool    isSorted( std::deque<int> & og, std::deque<int> & dq )
{
    std::sort(og.begin(), og.end());
      
    std::deque<int>::iterator ogIt = og.begin();
    for (std::deque<int>::iterator it = dq.begin(); it != dq.end(); ++it)
    {
        if (*it != *ogIt)
            return false;
        ++ogIt;
    }
    return true;
}

template <typename T>
static void printSimpleDeque(const std::deque<T>& dq) {
    typename std::deque<T>::const_iterator it;
    for (it = dq.begin(); it != dq.end(); ++it) {
        std::cout << "[" << *it << "] ";
    }
    std::cout << std::endl;
}

void algo(char **nums, int argc) {

    std::deque<int> dequeStack = getInp(nums, argc);
    int to_sort_size = dequeStack.size();
    std::deque<int> ogStack(dequeStack);

    clock_t	start;
	clock_t	end;

	// printDeque( dequeStack, 1, "Before" );

	start = std::clock();
    msi(dequeStack, to_sort_size, 1);
	end = std::clock();

	double	dequeTime = static_cast< double >( end - start ) * 1000000 / CLOCKS_PER_SEC;
	// printDeque( dequeStack, 1, "After" );
    // printDeque(dequeStack, 2, "misco");
    if (isSorted(ogStack, dequeStack))
        std::cout << GREEN BOLD << "DEQUE IS SORTED" << RESET << std::endl;
    else
        std::cout << RED BOLD << "DEQUE IS NOT SORTED" << RESET << std::endl;

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
