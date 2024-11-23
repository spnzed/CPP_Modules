/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:18:31 by aaespino          #+#    #+#             */
/*   Updated: 2024/11/23 13:10:25 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

void algo(char **nums, int argc) {

    std::deque<int> stack = getInp(nums, argc);
    int to_sort_size = stack.size();

    msi(stack, to_sort_size, 1);
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
