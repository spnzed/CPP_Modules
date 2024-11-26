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


    for (int i = 1; i < it_end; i++) {
        
        if (j_numbers[i] <= it_end && j_numbers[i]) {
            limit += ((((j_numbers[i]) * group_size) * 2));
        }

        int subtract = it_end % 2 == 0 ? 2 : 1;

        if (limit - 1 >= (it_end * group_size) - 1) {
            limit = (it_end - subtract) * group_size;
        }

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

            chain_B.insert(chain_B.begin() + insert_pos, first, second);

            if (j - (group_size * 2) <= prev) 
                prev = limit;
        }
    }

    if (stack.size() > chain_B.size())
        chain_B.insert(chain_B.end(), stack.begin() + chain_B.size(), stack.end());

    stack = chain_B;

}

static void min_size(std::deque<int>& stack, std::deque<int>& chain_B, std::vector<int> j_numbers,
            int it_end, int end, int group_size) {

    int prev = 1;
    int limit = 0;

    for (int i = 1; i < it_end; i += 1) {
        
        if (j_numbers[i] <= it_end && j_numbers[i]) {
            limit += ((((j_numbers[i]) * group_size) * 2));
        }

        int subtract = it_end % 2 == 0 ? 2 : 1;
        while (limit >= end) {
            limit = end - subtract;
        }

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

            chain_B.insert(chain_B.begin() + insert_pos, *first);

            if (j - (group_size * 2) <= prev) 
                prev = limit;
        }
    }
    stack = chain_B;
}

void insertWithJacobsthal(std::deque<int>& stack, int end, int group_size) {

    std::deque<int> chain_B = getStack(stack, int(stack.size()), group_size, 1);

    chain_B.insert(chain_B.begin(), stack.begin(), stack.begin() + group_size);

    int it_end = end / group_size;
    std::vector<int> j_numbers = jacobsthal(it_end);

    if (group_size ==  1) {
        min_size(stack, chain_B, j_numbers, it_end, end, group_size);
    } else {
        big_size(stack, chain_B, j_numbers, it_end, end, group_size);
    }
}
