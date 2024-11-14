/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:18:31 by aaespino          #+#    #+#             */
/*   Updated: 2024/11/14 18:50:25 by aaespino         ###   ########.fr       */
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

#include <deque>
#include <vector>
#include <cstdlib>

struct Stack {
    std::vector<Stack_node> left;
    std::vector<Stack_node> right;
};

int search_pos(int num, std::deque<int>& chain) {
    for (int i = 0; i < int(chain.size()); ++i) {
        if (chain[i] == num) {
            return i; // Devuelve la posición si encuentra el número
        }
    }
    return -1; // Devuelve -1 si no encuentra el número
}

void insertWithJacobsthal(std::deque<int>& chain, Stack_node* to_sort, int mid) {
    std::vector<int> j_numbers = jacobsthal(mid);

    // for (int i = 0; i < mid; i++) {
	//     chain.push_back(to_sort[i].right);
    // }

	chain.push_front(to_sort[0].left);

	int prev = 0;
	int limit = 0;

    for (int i = 1; i < mid; i++) {

        if (j_numbers[i] <= mid)
			limit += j_numbers[i];
        if (limit > mid)
			limit = mid - 1;
		for (int j = limit; j > prev && j <= mid; j--) {

			int b_value = to_sort[j].left;
			int b_pair = search_pos(to_sort[j].right, chain);
			int insert_pos = customUpperBound(chain, 0, b_pair, b_value);

			chain.insert(chain.begin() + insert_pos, b_value);

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

void msi(std::deque<int>& chain, std::deque<int>& stack, int start, int end, int size) {

    // Caso base: si el segmento tiene un solo elemento o está vacío
    if (size > end) {
        return;
    }

    // // Asegurarse de que `end` no sea menor que el número de elementos
    int actual_end = end;

    if (stack.size() % 2 != 0) {
        end -= size;
    }

    (void)actual_end;

    // 1. Pair swapping
    Stack_node* to_sort = new Stack_node[end];

    for (int i = 0; i < end; i++) {
        to_sort[i].left = stack[i * 2];
        to_sort[i].right = stack[i * 2 + 1];
    }

    stack = pairSwap(to_sort, end, size);

    printChain(stack);

    delete[] to_sort;

    if (size == 0) {
        msi(chain, stack, start, end, 1);
    } else {
        msi(chain, stack, start, end, size * 2);
    }
}

void algo(char **nums, int argc) {
    // 0. Stacks & size
    std::deque<int> stack = getInp(nums, argc);
    std::deque<int> chain;
    int to_sort_size = stack.size() / 2;

    // 3. Llamar a msi para ordenar e insertar
    msi(chain, stack, 0, to_sort_size, 0);
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
