/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jacobsthal.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:19:02 by aaespino          #+#    #+#             */
/*   Updated: 2024/11/21 18:13:52 by aaespino         ###   ########.fr       */
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

// Función para insertar con el algoritmo de Jacobsthal usando std::deque
void insertWithJacobsthal(std::deque<int>& stack, int end, int group_size) {

    std::cout << std::endl;
    std::cout << YELLOW << "-----------------------------------------------------------------" << RESET << std::endl;
    std::cout << std::endl;

    std::deque<int> chain_B = getStack(stack, int(stack.size()), group_size, 1);
    printDeque(stack, group_size, "Full Stack");

    chain_B.insert( chain_B.begin(), stack.begin(), stack.begin() + group_size );

    // printDeque(chain_B, group_size, "Stack b (AFTER FIRST INSERTION)");

    int prev = 0;
    int limit = 0;

    int it_end = end / group_size;

    std::vector<int> j_numbers = jacobsthal(it_end);

    int it_size = group_size;

    for (int i = 1; i < it_end; i+=2) {
    
        if (j_numbers[i] <= it_end && j_numbers[i])
            limit += ((((j_numbers[i]) * group_size) * 2)) - 1;

        if (limit > it_end * group_size)
            limit = ((it_end - 1) * group_size);

        for (int j = (limit); j > prev && j <= end; j-=(it_size * 2)) {

            int a_value = stack[j + group_size];

            int b_value = 0;
            if (j + group_size + group_size > int(stack.size())) {
                b_value = -1;
            } else {
                b_value = stack[j + group_size + group_size];
            }

            int b_position = search_pos(b_value, chain_B, group_size);

            int insert_pos = binarySearch(chain_B, b_position, a_value, group_size);

            // std::cout << std::endl;
            // std::cout << BLUE << "Insert stack:\t[" << stack[j + 1] << "\t...\t" << stack[j + group_size] << "]" << RESET << std::endl;
            // std::cout << "\t\t\t\t↓" << std::endl;
            // std::cout << RED << "Insert Behind:\t[" << stack[insert_pos] << "\t...\t" << stack[insert_pos + group_size - 1] << "]" << RESET << std::endl;
            // std::cout << std::endl;

            // REMEMBER To use insert with iterators
            std::deque< int >::iterator first = stack.begin() + j + 1;
            std::deque< int >::iterator second = stack.begin() + j + group_size + 1;
            chain_B.insert( chain_B.begin() + insert_pos - group_size, first, second);
            // printDeque(chain_B, group_size, "Stack b (AFTER JACOB)");

            if (j - (it_size * 2) <= prev) 
                prev = limit;
        }
    }

    stack = chain_B;
}
