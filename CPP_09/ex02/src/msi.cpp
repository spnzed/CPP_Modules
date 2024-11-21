/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msi.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:16:09 by aaespino          #+#    #+#             */
/*   Updated: 2024/11/21 19:00:10 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

static std::deque<int> pairSwap(std::deque<int>& stack, int end, int group_size) {
    
    std::deque<int> result;
    Stack_node* to_sort = new Stack_node[end];

    for (int i = 0; i < end; i++) {
        to_sort[i].left = stack[i * 2];
        to_sort[i].right = stack[i * 2 + 1];
    }

    if (group_size == 1) {
        for (int i = 0; i < end; ++i) {
            if (to_sort[i].left > to_sort[i].right) {
                std::swap(to_sort[i].left, to_sort[i].right);
            }
        }
    } else {
        group_size /= 2;
        for (int i = 0; i < end; i += group_size) {
            // Verificar que no nos salimos de los límites
            if (i + group_size >= end) break;

            int rightmost_first_group = to_sort[i + group_size - 1].right;
            int rightmost_second_group = to_sort[i + group_size].right;

            // Intercambiar grupos si es necesario
            if (rightmost_first_group > rightmost_second_group) {
                for (int j = 0; j < group_size; ++j) {
                    if (i + group_size + j >= end) break; // Verificar límites
                    std::swap(to_sort[i + j], to_sort[i + group_size + j]);
                }
            }
        }
    }

    // Construir el resultado
    for (int i = 0; i < end; i++) {
        result.push_back(to_sort[i].left);
        result.push_back(to_sort[i].right);
    }

    delete[] to_sort;
    return result;
}

void msi(std::deque<int>& stack, int start, int end, int size) {

    // Caso base: si el segmento tiene un solo elemento o está vacío
    if (size > end) {
        return;
    }

    // int actual_end = end;

    if (end % 2 != 0)
        end -= size;

    // 1. Pair swapping
    stack = pairSwap(stack, end / 2, size);

    printDeque(stack, size, "MSI");

    // 2. Rec
    msi(stack, start, end, size * 2);

    // 3. Jacob
    // if (stack.size() / size >= 4)
        // insertWithJacobsthal(stack, actual_end, size);
}
