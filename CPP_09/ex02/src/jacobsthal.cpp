/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jacobsthal.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:19:02 by aaespino          #+#    #+#             */
/*   Updated: 2024/11/23 18:16:20 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

static std::vector<int> jacobsthal(int n) {
    std::vector<int> j(n);
    if (n > 0) j[0] = 0 * 2;
    if (n > 1) j[1] = 1 * 2;
    for (int i = 2; i < n; ++i) {
        j[i] = (j[i - 1] + 2 * j[i - 2]);
    }
    return j;
}

static int search_pos(int num, std::deque<int>& chain, int size) {

    if (num == -1) 
        return int(chain.size()) / size;

    for (int i = size - 1; i < int(chain.size()); i+=size) 
        if (chain[i] == num) return i / size; // Devuelve la posición si encuentra el número, convertida a size

    return int(chain.size()) / size;
}

static void big_size(std::deque<int>& stack, std::deque<int>& chain_B, std::vector<int> j_numbers,
            int it_end, int end, int group_size) {
    
    int prev = 1;
    int limit = 0;

    for (int i = 1; i < it_end; i += 2) {
        
        if (j_numbers[i] <= it_end && j_numbers[i]) {
            // std::cout << YELLOW << "Suma Jacob" << RESET << std::endl;
            // std::cout << YELLOW << it_end << RESET << std::endl;
            // std::cout << YELLOW << j_numbers[i] << RESET << std::endl;
            limit += ((((j_numbers[i]) * group_size) * 2)) - 1;
        }

        while (limit > end) {
            // std::cout << YELLOW << "Resetea al ultimo" << RESET << std::endl;
            limit = ((it_end - 2) * group_size) - 1;
        }

        // std::cout << "Iteration i=" << i << ", limit=" << limit << ", prev=" << prev << std::endl;
        // std::cout << "limit adjusted to: " << limit << " after checks" << std::endl;

        for (int j = limit; j > prev && j <= end; j -= (group_size * 2)) {
            // std::cout << "Inner loop: j=" << j << ", group_size=" << group_size << std::endl;
            // std::cout << " in J - 1 [ " << stack[j - 1] << " " << stack[j + group_size - 1] << " ] " << std::endl;

            int a_value = stack[j + group_size];

            int b_value = 0;
            if (j + group_size + group_size > int(stack.size())) {
                b_value = -1;
            } else {
                b_value = stack[j + group_size + group_size];
            }

            // std::cout << "a_value: " << a_value << ", b_value: " << b_value << std::endl;

            int b_position = search_pos(b_value, chain_B, group_size);

            // std::cout << "b_position (from search_pos): " << b_position << std::endl;

            int insert_pos = binarySearch(chain_B, b_position, a_value, group_size);

            // std::cout << "Binary Search -> Insert position: " << insert_pos << std::endl;

            // std::cout << std::endl;
            // std::cout << BLUE << "Insert stack:\t[" << stack[j + 1] << "\t...\t" << stack[j + group_size] << "]" << RESET << std::endl;
            // std::cout << "\t\t\t\t↓" << std::endl;
            // std::cout << RED << "Insert Behind:\t[" << chain_B[insert_pos] << "\t...\t" << chain_B[insert_pos + group_size - 1] << "]" << RESET << std::endl;
            // std::cout << std::endl;

            std::deque<int>::iterator first = stack.begin() + j + 1;
            std::deque<int>::iterator second = stack.begin() + j + group_size + 1;

            // std::cout << "Inserting range from stack: ";
            for (std::deque<int>::iterator it = first; it != second; ++it) {
                // std::cout << *it << " ";
            }
            // std::cout << "at position: " << insert_pos << " in chain_B." << std::endl;

            chain_B.insert(chain_B.begin() + insert_pos, first, second);
            // printDeque(chain_B, group_size, "Stack b (AFTER JACOB)");

            if (j - (group_size * 2) <= prev) 
                prev = limit;
        }
    }

    // std::cout << "Final stack contents after Jacobsthal: ";
    // for (std::deque<int>::const_iterator it = stack.begin(); it != stack.end(); ++it) {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;

    stack = chain_B;

    printDeque(stack, group_size, "Final stack contents after Jacobsthal");

}

static void min_size(std::deque<int>& stack, std::deque<int>& chain_B, std::vector<int> j_numbers,
            int it_end, int end, int group_size) {
    
    int prev = 1;
    int limit = 0;

    // printDeque(stack, group_size, "Full Stack");
    // printDeque(chain_B, group_size, "Chain");

    for (int i = 1; i < it_end; i += 1) {
        
        if (j_numbers[i] <= it_end && j_numbers[i]) {
            limit += ((((j_numbers[i]) * group_size) * 2));
            // std::cout << YELLOW << "Limit despues de Jacob" << RESET << std::endl;
            // std::cout << YELLOW << limit << RESET << std::endl;
            // std::cout << YELLOW << "it_end: " << it_end << RESET << std::endl;
        }

        while (limit >= end) {
            // std::cout << YELLOW << "Resetea al ultimo" << RESET << std::endl;
            limit = ((it_end - 1) * group_size) - 1;
        }

        // std::cout << "Iteration i=" << i << ", limit=" << limit << ", prev=" << prev << std::endl;
        // std::cout << "limit adjusted to: " << limit << " after checks" << std::endl;

        for (int j = limit; j > prev && j <= end; j -= (group_size * 2)) {
            // std::cout << "Inner loop: j=" << j << ", group_size=" << group_size << std::endl;
            // std::cout << " in J - 1 [ " << stack[j - 1] << " " << stack[j + group_size - 1] << " ] " << std::endl;

            int a_value = stack[j];

            int b_value = 0;
            if (j + group_size + group_size > int(stack.size())) {
                b_value = -1;
            } else {
                b_value = stack[j + 1];
            }

            // std::cout << "a_value: " << a_value << ", b_value: " << b_value << std::endl;

            int b_position = search_pos(b_value, chain_B, group_size);

            // std::cout << "b_position (from search_pos): " << b_position << std::endl;

            int insert_pos = binarySearch(chain_B, b_position, a_value, 1);

            // std::cout << "Binary Search -> Insert position: " << insert_pos << std::endl;

            // std::cout << std::endl;
            // std::cout << BLUE << "Insert stack:\t[" << stack[j] << "]" << RESET << std::endl;
            // std::cout << "\t\t  ↓" << std::endl;
            // std::cout << RED << "Insert Behind:\t[" << chain_B[insert_pos] << "]" << RESET << std::endl;
            // std::cout << std::endl;

            std::deque<int>::iterator first = stack.begin() + j;
            std::deque<int>::iterator second = stack.begin() + j + 1;

            // std::cout << "Inserting range from stack: ";
            for (std::deque<int>::iterator it = first; it != second; ++it) {
                // std::cout << *it << " ";
            }
            // std::cout << "at position: " << insert_pos << " in chain_B." << std::endl;

            chain_B.insert(chain_B.begin() + insert_pos, first, second);
            // printDeque(chain_B, group_size, "Stack b (AFTER JACOB)");

            if (j - (group_size * 2) <= prev) 
                prev = limit;
        }
    }

    stack = chain_B;

    printDeque(stack, group_size, "Final stack contents after Jacobsthal");
    
}

void insertWithJacobsthal(std::deque<int>& stack, int end, int group_size) {
    std::cout << std::endl;
    std::cout << YELLOW << "-----------------------------------------------------------------" << RESET << std::endl;
    std::cout << std::endl;

    std::deque<int> chain_B = getStack(stack, int(stack.size()), group_size, 1);
    // printDeque(stack, group_size, "Full Stack");

    chain_B.insert(chain_B.begin(), stack.begin(), stack.begin() + group_size);

    // printDeque(chain_B, group_size, "Stack b (AFTER FIRST INSERTION)");

    // std::cout << "Initial stack contents: ";
    // for (std::deque<int>::const_iterator it = stack.begin(); it != stack.end(); ++it) {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;

    // std::cout << "END: " << end << std::endl;
    int it_end = end / group_size;

    std::vector<int> j_numbers = jacobsthal(it_end);

    std::cout << "Generated Jacobsthal numbers: ";
    for (std::vector<int>::const_iterator it = j_numbers.begin(); it != j_numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // std::cout << "it_end: " << it_end << ", group_size: " << group_size << std::endl;

    if (group_size ==  1) {
        min_size(stack, chain_B, j_numbers, it_end, end, group_size);
    } else {
        big_size(stack, chain_B, j_numbers, it_end, end, group_size);
    }
}
