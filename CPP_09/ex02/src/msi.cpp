/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msi.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:16:09 by aaespino          #+#    #+#             */
/*   Updated: 2024/11/20 15:43:04 by aaespino         ###   ########.fr       */
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

    int actual_end = end;

    if (end % 2 != 0)
        end -= size;

    // 1. Pair swapping
    stack = pairSwap(stack, end / 2, size);

    // 2. Rec
    msi(stack, start, end, size * 2);

    // 3. Jacob
    if (stack.size() / size >= 4)
        insertWithJacobsthal(stack, actual_end, size);
}
