/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:18:31 by aaespino          #+#    #+#             */
/*   Updated: 2024/11/19 18:42:36 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"
#include "PmergeMe_utils.cpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

#include <algorithm>  // Necesario para std::find

#include <deque>
#include <vector>
#include <cstdlib>

#include <cstdio>
#include <string>
#include <iostream>

struct Stack {
    std::vector<Stack_node> left;
    std::vector<Stack_node> right;
};

int search_pos(int num, std::deque<int>& chain, int size) {

    for (int i = size - 1; i < int(chain.size()); i+=size) {
        if (chain[i] == num) {
            return i; // Devuelve la posición si encuentra el número
        }
    }
    return -1; // Devuelve -1 si no encuentra el número
}

std::deque<int> getStack(std::deque<int>& stack, int end, int group_size, int side) {
    std::deque<int> chain;

    if (group_size > 0) {
        if (side == 0) {
            std::deque< int >::iterator it = stack.begin();
            size_t pos = 0;
            while ( pos + group_size <= stack.size() ) {
                chain.insert( chain.end(), it + pos, it + pos + group_size );
                pos += group_size * 2;
            }
        } else {
            std::deque< int >::iterator it = stack.begin();
            size_t pos = group_size;
            while ( pos + group_size <= stack.size() ) {
                chain.insert( chain.end(), it + pos, it + pos + group_size );
                pos += group_size * 2;
            }
        }   
    } else {
        if (side == 0) {
            for (int i = 0; i < end / 2; i++) {
                chain.push_back(stack[i * 2]);
            }
        } else {
            for (int i = 0; i < end / 2; i++) {
                chain.push_back(stack[i * 2 + 1]);
            }
        }
    }

    return chain;
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

std::deque<int> pairSwap(Stack_node* to_sort, int end, int group_size) {
    std::deque<int> result;

    // Si el tamaño del grupo es 0, se asegura que el valor más grande esté en la posición 'right' de cada pareja
    if (group_size == 0) {
        for (int i = 0; i < end; ++i) {
            // Si el valor de 'left' es mayor que 'right', los intercambiamos
            if (to_sort[i].left > to_sort[i].right) {
                std::swap(to_sort[i].left, to_sort[i].right);
                // std::swap_ranges(it, it + group_size - 1, it + group_size);
            }
        }
    } else {
        // Recorremos los pares para comparar grupos de tamaño 'size'
        for (int i = 0; i + group_size < end; i += group_size * 2) {
            // Si estamos comparando el último grupo que no llena el tamaño, no lo procesamos
            if (i + group_size * 2 > end) break;

            // Comparar la última pareja de cada grupo
            int rightmost_first_group = to_sort[i + group_size - 1].right;
            int rightmost_second_group = to_sort[i + group_size * 2 - 1].right;

            // Si el valor 'right' del primer grupo es mayor, se intercambian las parejas
            if (rightmost_first_group > rightmost_second_group) {
                for (int j = 0; j < group_size; ++j) {
                    std::swap(to_sort[i + j], to_sort[i + group_size + j]);
                }
            }
        }
    }

    // Recopilar los resultados en el deque
    for (int i = 0; i < end; i++) {
        result.push_back(to_sort[i].left);
        result.push_back(to_sort[i].right);
    }

    return result;
}

void msi(std::deque<int>& stack, int start, int end, int size) {

    // Caso base: si el segmento tiene un solo elemento o está vacío
    if (size > end) {
        return;
    }

    int actual_end = end;

    if (end % 2 != 0)
        end -= size;

    // 1. Pair swapping
    Stack_node* to_sort = new Stack_node[end / 2];

    for (int i = 0; i < end / 2; i++) {
        to_sort[i].left = stack[i * 2];
        to_sort[i].right = stack[i * 2 + 1];
    }

    stack = pairSwap(to_sort, end / 2, size);
    
    delete[] to_sort;

    // 2. Rec
    msi(stack, start, end, size * 2);

    // 3. Jacob
    if (stack.size() / size >= 4)
        insertWithJacobsthal(stack, actual_end, size);
}

void algo(char **nums, int argc) {
    // 0. Stacks & size
    std::deque<int> stack = getInp(nums, argc);
    int to_sort_size = stack.size();

    // 3. Llamar a msi para ordenar e insertar
    msi(stack, 0, to_sort_size, 1);
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
