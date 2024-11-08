/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:18:31 by aaespino          #+#    #+#             */
/*   Updated: 2024/11/07 22:44:49 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"
#include "PmergeMe_utils.cpp"

int customUpperBound(const std::deque<int>& chain, int start, int end, int value) {
    int low = start;
    int high = end;
    while (low < high) {
        int mid = (low + high) / 2;
        if (chain[mid] <= value) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

void recursiveMergeInsert(std::deque<int>& chain, Stack* to_sort, int start, int end) {
    if (start > end) {
        return;
    }

    // Hacer el swap de pares al ingresar a la función recursiva
    if (start < end && to_sort[start].right < to_sort[start].left) {
        std::swap(to_sort[start].left, to_sort[start].right);
    }

    if (start == end) {
        // Inserción en orden de `right`
        std::deque<int>::iterator it = std::lower_bound(chain.begin(), chain.end(), to_sort[start].right);
        chain.insert(it, to_sort[start].right);
        return;
    }

    int middle = start + (end - start) / 2;

    // Llamadas recursivas para cada mitad
    recursiveMergeInsert(chain, to_sort, start, middle - 1);
    recursiveMergeInsert(chain, to_sort, middle + 1, end);

    // Inserción de `right` del elemento medio
    std::deque<int>::iterator it = std::lower_bound(chain.begin(), chain.end(), to_sort[middle].right);
    chain.insert(it, to_sort[middle].right);
}

void recursiveJacobsthalInsert(std::deque<int>& chain, Stack* to_sort, int start, int end) {
    if (start > end) {
        return;
    }
    
    int mid = start + (end - start) / 2;
    recursiveJacobsthalInsert(chain, to_sort, start, mid - 1);
    recursiveJacobsthalInsert(chain, to_sort, mid + 1, end);

    int insert_pos = customUpperBound(chain, 0, int(chain.size()), to_sort[mid].left);
    chain.insert(chain.begin() + insert_pos, to_sort[mid].left);
}

void algo(char **nums, int argc) {
    std::deque<int> stack = getInp(nums, argc);
    std::deque<int> chain;

    int to_sort_size = stack.size() / 2;
    Stack* to_sort = new Stack[to_sort_size];

    for (int i = 0; i < to_sort_size; i++) {
        to_sort[i].left = stack[i * 2];
        to_sort[i].right = stack[i * 2 + 1];
    }

    printToSort(to_sort, to_sort_size);

    recursiveMergeInsert(chain, to_sort, 0, to_sort_size - 1);

    std::cout << "Chain A:" << std::endl;
    for (int i = 0; i < int(chain.size()); i++) {
        std::cout << chain[i] << "; ";
    }
    std::cout << std::endl;

    recursiveJacobsthalInsert(chain, to_sort, 0, to_sort_size - 1);

    std::cout << "Final Chain:" << std::endl;
    for (int i = 0; i < int(chain.size()); i++) {
        std::cout << chain[i] << "; ";
    }
    std::cout << std::endl;

    delete[] to_sort;
}

int main(int argc, char **argv) {
    if (argc <= 2) {
        std::cout << "Error: invalid input." << std::endl;
        return 1;
    } else {
        if (compArgs(argv, argc)) {
            algo(argv, argc);
        }
    }
    return 0;
}
