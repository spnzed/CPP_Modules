/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe_utils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:29:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/11/07 22:34:54 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

#include <iostream>
#include <deque>
#include <vector>
#include <cstdlib>

struct Stack {
    int left;
    int right;
};

std::vector<int> jacobsthal(int n) {
    std::vector<int> j(n);
    if (n > 0) j[0] = 0 * 2;
    if (n > 1) j[1] = 1 * 2;
    for (int i = 2; i < n; ++i) {
        j[i] = (j[i - 1] + 2 * j[i - 2]);
    }
    return j;
}

int compRep(int target, char** set, int limit) {

	for (int i = 0; i < limit; i++) {
		if (target == atoi(set[i]))
			return 1;
	}

	return 0;
}

int compArgs(char **argv, int argc) {

	for (int i = 1; i < argc; i++) {
		try {
			int num = atoi(argv[i]);

			if (compRep(num, argv + 1, i - 1))
				return 0;
			if (num < 1) {
				std::cout << "Error" << std::endl;
				return 0;
			}
		} catch (std::exception & e) {
			std::cout << "Error" << std::endl;
			return 0;
		}
	}
	return 1;
}

std::deque<int> getInp(char **nums, int argc) {
	
	std::deque<int> main;

	for (int i = 1; i < argc; i++) {
		main.push_back(atoi(nums[ i ]));
	}

	return main;
}

void printChain(const std::deque<int>& chain) {
    std::cout << "Final Chain:" << std::endl;
    for (std::deque<int>::const_iterator it = chain.begin(); it != chain.end(); ++it) {
        std::cout << *it << "; ";
    }
    std::cout << std::endl;
}

void printToSort(const Stack* to_sort, int size) {
    std::cout << "Contents of to_sort:" << std::endl;
    for (const Stack* it = to_sort; it < to_sort + size; ++it) {
        std::cout << "Left: " << it->left << ", Right: " << it->right << std::endl;
    }
}
