/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jacobsthal.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:19:02 by aaespino          #+#    #+#             */
/*   Updated: 2024/11/25 19:49:14 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

static std::vector<int> jacobsthal(int n) {
    std::vector<int> j(n);
    if (n > 0) j[0] = 0 * 2;
    if (n > 1) j[1] = 1 * 2;
    for (int i = 2; i < n; ++i) {
        j[i] = (j[i - 1] + 2 * j[i - 2]);
        // std::cout << "j[" << i << "] = " << j[i] << std::endl;
    }
    return j;
}

static int search_pos(int num, std::deque<int>& chain, int size) {

    if (num == -1) 
        return int(chain.size()) / size;

    for (int i = size - 1; i < int(chain.size()); i+=size) 
        if (chain[i] == num) return i / size;

    return int(chain.size()) / size;
}

static void big_size(std::deque<int>& stack, std::deque<int>& chain_B, std::vector<int> j_numbers,
            int it_end, int end, int group_size) {

    int prev = 1;
    int limit = 0;

    // std::cout << "ADIOS ADIOS ADIOS" << it_end << std::endl;

    for (int i = 1; i < it_end; i++) {
        
        if (j_numbers[i] <= it_end && j_numbers[i]) {
            // std::cout << "limit = " << limit << std::endl;
            // std::cout << "next jacob value = " << ((((j_numbers[i]) * group_size) * 2)) - 1 << std::endl; 
            limit += ((((j_numbers[i]) * group_size) * 2));
            // std::cout << "j_numbers[" << i << "](" << j_numbers[i] << ") * " << group_size << " * 2 = " << ((((j_numbers[i]) * group_size) * 2)) << std::endl;
            // std::cout << "new limit = " << limit << std::endl;
        }

        // std::cout << "it_end = " << it_end << std::endl;
        int subtract = it_end % 2 == 0 ? 2 : 1;

        if (limit - 1 >= (it_end * group_size) - 1) {
            // std::cout << YELLOW "OUT OF LIMIT NOSEQUE" RESET << std::endl;
            // std::cout << YELLOW << "SUBTRACT: " << subtract << RESET << std::endl;
            limit = (it_end - subtract) * group_size;
            // std::cout << CYAN BOLD "limit = " RESET << limit << std::endl;
            // limit = ((it_end - subtract) * group_size);
        }

        // std::cout << "j loop start" << std::endl;
        // std::cout << "group size = " << group_size << std::endl;
        // std::cout << "Limit = " << limit << std::endl;
        // std::cout << "Prev = " << prev << std::endl;
        // std::cout << "End = " << end << std::endl;
        // size_t insertions = 0;
        for (int j = limit - 1; j > prev && j <= end; j -= (group_size * 2)) {
            
            int a_value = stack[j + group_size];

            int b_value = 0;
            if (j + group_size + group_size > int(stack.size())) {
                b_value = -1;
            } else {
                b_value = stack[j + group_size + group_size];
            }

            int b_position = search_pos(b_value, chain_B, group_size);
            int insert_pos = binarySearch(chain_B, b_position, a_value, group_size);

            std::deque<int>::iterator first = stack.begin() + j + 1;
            std::deque<int>::iterator second = stack.begin() + j + group_size + 1;

            // std::cout << "Inserting [" << *first << " to " << *second << ")" << std::endl;
            // std::cout << "At position: " << *(chain_B.begin() + insert_pos) << std::endl;

            chain_B.insert(chain_B.begin() + insert_pos, first, second);
            // insertions++;

            if (j - (group_size * 2) <= prev) 
                prev = limit;
        }
        // std::cout << "INSERTIONS IN THIS LOOP = " << insertions << std::endl;
    }

    // Falta anyadir los leftovers antes de hacer stack = chain_B, por eso se pierden
    if (stack.size() > chain_B.size())
        chain_B.insert(chain_B.end(), stack.begin() + chain_B.size(), stack.end());

    stack = chain_B;

    // printDeque(stack, group_size, "Final stack contents after Jacobsthal");
}

static void min_size(std::deque<int>& stack, std::deque<int>& chain_B, std::vector<int> j_numbers,
            int it_end, int end, int group_size) {

    int prev = 1;
    int limit = 0;

    for (int i = 1; i < it_end; i += 1) {
        
        if (j_numbers[i] <= it_end && j_numbers[i]) {
            limit += ((((j_numbers[i]) * group_size) * 2));
        }

        // it_end--; // Solo cuando sean impares??
        int subtract = it_end % 2 == 0 ? 2 : 1;
        while (limit >= end) {
            // std::cout << "OUT OF LIMIT NOSEQUE" << std::endl;
            // std::cout << YELLOW << "SUBTRACT: " << subtract << RESET << std::endl;
            limit = end - subtract;
            // std::cout << "limit = " << limit << std::endl;
        }
        
        
        // std::cout << "Limit = " << limit << std::endl;

        for (int j = limit; j > prev && j <= end; j -= (group_size * 2)) {

            int a_value = stack[j];
            int b_value = 0;

            if (j + group_size + group_size > int(stack.size())) {
                b_value = -1;
            } else {
                b_value = stack[j + 1];
            }

            int b_position = search_pos(b_value, chain_B, group_size);
            int insert_pos = binarySearch(chain_B, b_position, a_value, 1);

            std::deque<int>::iterator first = stack.begin() + j;

            // std::cout << "Jacob " << GREEN << j_numbers[i] << RESET << std::endl;
            // std::cout << "Limit " << BLUE << limit << RESET << std::endl;
            // std::cout << "Inserting " << RED << *first << RESET << std::endl;
            // std::cout << "At position: " << *(chain_B.begin() + insert_pos) << std::endl;

            chain_B.insert(chain_B.begin() + insert_pos, *first);

            // printDeque(chain_B, group_size, "after jacob");

            if (j - (group_size * 2) <= prev) 
                prev = limit;
        }
    }

    // !!!!!! AQUI

    // Falta anyadir los leftovers antes de hacer stack = chain_B, por eso se pierden
    // if (stack.size() > chain_B.size())
    //     chain_B.insert(chain_B.end(), stack.begin() + chain_B.size(), stack.end());

    stack = chain_B;

    // printDeque(stack, group_size, "Final stack contents after Jacobsthal");
}

void insertWithJacobsthal(std::deque<int>& stack, int end, int group_size) {

    // std::cout << BLUE BOLD << "> > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >  INSERT JACOB IN" << RESET << std::endl;
    // std::cout << MAGENTA;
    // printDeque(stack, group_size, "Full Stack");
    // std::cout << RESET;
    // std::cout << "end = " << end << std::endl;
    // std::cout << "stack[end] = " << stack[end] << std::endl;

    std::deque<int> chain_B = getStack(stack, int(stack.size()), group_size, 1);

    // std::cout << YELLOW;
    // printDeque(chain_B, group_size, "Chain");
    // std::cout << RESET;

    chain_B.insert(chain_B.begin(), stack.begin(), stack.begin() + group_size);

    // std::cout << YELLOW;
    // printDeque(chain_B, group_size, "After 1st insert");
    // std::cout << RESET;

    int it_end = end / group_size;
    // std::cout << "it_end = " << it_end << std::endl;
    std::vector<int> j_numbers = jacobsthal(it_end);

    if (group_size ==  1) {
        min_size(stack, chain_B, j_numbers, it_end, end, group_size);
    } else {
        big_size(stack, chain_B, j_numbers, it_end, end, group_size);
    }

    std::cout << RED;
    // std::cout << "STACK SIZE AFTER JACOB: " << stack.size() << std::endl;
    // printDeque(stack, group_size, "After jacob");
    // printDeque(stack, 8, "8 size");
    std::cout << RESET;
    // std::cout << ">>> INSERT JACOB OUT" << std::endl;
}
