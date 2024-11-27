/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:18:31 by aaespino          #+#    #+#             */
/*   Updated: 2024/11/28 00:05:30 by aaronespino      ###   ########.fr       */
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

bool    isSorted( std::vector<int> & og, std::vector<int> & vec )
{
    std::sort(og.begin(), og.end());
      
    std::vector<int>::iterator ogIt = og.begin();
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
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
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void algo(char **nums, int argc) {

    std::deque<int> dequeStack = getDeque(nums, argc);
    std::vector<int> vectorStack = getVector(nums, argc);

    std::deque<int> ogDeque(dequeStack);
    std::vector<int> ogVector(vectorStack);

    clock_t	start_dq;
	clock_t	end_dq;

    clock_t	start_vec;
	clock_t	end_vec;

    std::cout << "Before:\t" ;
    printSimpleDeque(dequeStack);

	start_dq = std::clock();
    msi(dequeStack, dequeStack.size(), 1);
	end_dq = std::clock();

    std::cout << "After:\t" ;
    printSimpleDeque(dequeStack);

    start_vec = std::clock();
    msi(vectorStack, vectorStack.size(), 1);
	end_vec = std::clock();

	double	dequeTime = static_cast< double >( end_dq - start_dq ) * 1000000 / CLOCKS_PER_SEC;
	double	vectorTime = static_cast< double >( end_vec - start_vec ) * 1000000 / CLOCKS_PER_SEC;

    // if (isSorted(ogDeque, dequeStack))
    //     std::cout << GREEN BOLD << "DEQUE IS SORTED" << RESET << std::endl;
    // else
    //     std::cout << RED BOLD << "DEQUE IS NOT SORTED" << RESET << std::endl;

    // if (isSorted(ogVector, vectorStack))
    //     std::cout << GREEN BOLD << "VECTOR IS SORTED" << RESET << std::endl;
    // else
    //     std::cout << RED BOLD << "VECTOR IS NOT SORTED" << RESET << std::endl;

    std::cout << "Time to process a range of " << argc - 1 << " elements with std::[deque] : " << dequeTime << " us" << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::[vector] : " << vectorTime << " us" << std::endl;
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
