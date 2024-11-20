/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jacobsthal.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:19:02 by aaespino          #+#    #+#             */
/*   Updated: 2024/11/20 15:45:24 by aaespino         ###   ########.fr       */
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

    for (int i = size - 1; i < int(chain.size()); i+=size)
        if (chain[i] == num) return i; // Devuelve la posición si encuentra el número

    return -1; // Devuelve -1 si no encuentra el número
}

// Función para insertar con el algoritmo de Jacobsthal usando std::deque
void insertWithJacobsthal(std::deque<int>& stack, int end, int group_size) {

    std::deque<int> chain_B = getStack(stack, int(stack.size()), group_size, 1);
    printDeque(stack, group_size, "Full Stack");
    // printDeque(chain_B, group_size, "Stack b [Big]");

    // Se asume que jacobsthal devuelve una secuencia de números
    std::vector<int> j_numbers = jacobsthal(int(chain_B.size()) / group_size);

    chain_B.insert( chain_B.begin(), stack.begin(), stack.begin() + group_size );

    printDeque(chain_B, group_size, "Stack b (AFTER FIRST INSERTION)");

    int prev = 0;
    int limit = 0;

    int it_end = end / group_size;
    it_end = (it_end % 2 != 0) ? it_end - 1 : it_end;

    int it_size = group_size;

    for (int i = 1; i < it_end; i++) {
                                                                                                                                    // std::cout << "Jacob Index: " << j_numbers[i] << std::endl; 
        if (j_numbers[i] <= it_end)
            limit += (((j_numbers[i]) * group_size) * 2) + group_size - 1;

        if (limit > it_end * group_size)
            limit = ((it_end - 1) * group_size) - 1;
                                                                                                                                    // std::cout << "Limit: " << limit << RED << " EXPECTED: " << stack[ limit ] << RESET << std::endl; 
                                                                                                                                    // std::cout << "ItEnd: " << it_end << std::endl; 
        for (int j = limit; j > prev && j <= end; j-=it_size) {
                                                                                                                                    // std::deque< int >::iterator it = stack.begin() + group_size;
            int a_value = stack[j + group_size];
                                                                                                                                        // std::cout << "AVALUE: " << a_value << std::endl; 
            int b_position = search_pos(a_value, chain_B, group_size);

            int insert_pos = binarySearch(chain_B, 0, b_position, a_value);

            std::cout << chain_B[insert_pos] << "\t[" << insert_pos << "]" << std::endl;

            return ;
            // Insertar el valor en la posición correcta
            chain_B.insert( chain_B.begin() + insert_pos, a_value - group_size + 1, a_value);

            if (j - 1 == prev) {
                prev = limit;
            }
        }
    }
}
