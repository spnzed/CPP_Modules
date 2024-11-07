/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:18:31 by aaespino          #+#    #+#             */
/*   Updated: 2024/11/07 16:36:09 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

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
    int left;
    int right;
};

std::vector<int> jacobsthal(int n) {
    std::vector<int> j(n);
    if (n > 0) j[0] = 0 * 2;
    if (n > 1) j[1] = 1 * 2;
    for (int i = 2; i < n; ++i) {
        j[i] = (j[i - 1] + 2 * j[i - 2]);
    }
    return j;
}

int compRep(int target, char** set, int limit) {

	for (int i = 0; i < limit; i++) {
		if (target == atoi(set[i]))
			return 1;
	}

	return 0;
}

int compArgs(char **argv, int argc) {

	for (int i = 1; i < argc; i++) {
		try {
			int num = atoi(argv[i]);

			if (compRep(num, argv + 1, i - 1))
				return 0;
			if (num < 1) {
				std::cout << "Error" << std::endl;
				return 0;
			}
		} catch (std::exception & e) {
			std::cout << "Error" << std::endl;
			return 0;
		}
	}
	return 1;
}

std::deque<int> getInp(char **nums, int argc) {
	
	std::deque<int> main;

	for (int i = 1; i < argc; i++) {
		main.push_back(atoi(nums[ i ]));
	}

	return main;
}

std::deque<int> pairSwap(std::deque<int> input) {

	for (int i = 0; i < int(input.size() / 2); i++) {
		if (input[ i * 2 + 1 ] < input[ i * 2 ])
			std::swap(input[ i * 2 ], input[ i * 2 + 1]);
	}

	return input;
}

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

void insertWithJacobsthal(std::deque<int>& chain, Stack* to_sort, int mid) {
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
			int insert_pos = customUpperBound(chain, 0, int(chain.size()), b_value);
	
			chain.insert(chain.begin() + insert_pos, b_value);

			if (j - 1 == prev) {
				prev = limit;
			}			
		}
    }
}

void printChain(const std::deque<int>& chain) {
    std::cout << "Final Chain:" << std::endl;
    for (std::deque<int>::const_iterator it = chain.begin(); it != chain.end(); ++it) {
        std::cout << *it << "; ";
    }
    std::cout << std::endl;
}

void printToSort(const Stack* to_sort, int size) {
    std::cout << "Contents of to_sort:" << std::endl;
    for (const Stack* it = to_sort; it < to_sort + size; ++it) {
        std::cout << "Left: " << it->left << ", Right: " << it->right << std::endl;
    }
}

void mergeInsert(std::deque<int>& chain, Stack* to_sort, int start, int end) {
    // Caso base: si el segmento tiene un solo elemento o está vacío
    if (start > end) {
        return;
    }
    if (start == end) {
        // Insertar solo el elemento `right` de `to_sort[start]` en `chain` en orden
        std::deque<int>::iterator it = std::lower_bound(chain.begin(), chain.end(), to_sort[start].right);
        chain.insert(it, to_sort[start].right);
        return;
    }

    // Encuentra el punto medio
    int middle = start + (end - start) / 2;

    // Llamadas recursivas para las dos mitades
    mergeInsert(chain, to_sort, start, middle - 1); // Mitad izquierda
    mergeInsert(chain, to_sort, middle + 1, end);   // Mitad derecha

    // Insertar solo el elemento `right` de `to_sort[middle]` en `chain` de forma ordenada
    std::deque<int>::iterator it = std::lower_bound(chain.begin(), chain.end(), to_sort[middle].right);
    chain.insert(it, to_sort[middle].right);
}

void algo(char **nums, int argc) {
    // 0. Stacks
    std::deque<int> stack = getInp(nums, argc);
    std::deque<int> chain;

    // 1. Pair swapping
    stack = pairSwap(stack);

    // 2. Crear las dos cadenas en una estructura "Stack". Izquierda y derecha
    int to_sort_size = stack.size() / 2;
    Stack* to_sort = new Stack[to_sort_size];

    for (int i = 0; i < to_sort_size; i++) {
        to_sort[i].left = stack[i * 2];
        to_sort[i].right = stack[i * 2 + 1];
    }

	printToSort(to_sort, to_sort_size);

    // 3. Llamar a mergeInsert para ordenar e insertar
    mergeInsert(chain, to_sort, 0, to_sort_size - 1);

    // 4. Imprimir cadena A1
    std::cout << "Chain A:" << std::endl;
    for (int i = 0; i < int(chain.size()); i++) {
        std::cout << chain[i] << "; ";
    }
    std::cout << std::endl;

	insertWithJacobsthal(chain, to_sort, stack.size() / 2);

	// 4. Imprimir final
    std::cout << "Final Chain:" << std::endl;
    for (int i = 0; i < int(chain.size()); i++) {
        std::cout << chain[i] << "; ";
    }
    std::cout << std::endl;

    // Liberar memoria
    delete[] to_sort;
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
