/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:18:31 by aaespino          #+#    #+#             */
/*   Updated: 2024/11/04 21:13:07 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

#include <deque>
#include <vector>
#include <cstdlib>

struct Stack {
    int left;
    int right;
};

std::vector<int> jacobsthal(int n) {
    std::vector<int> j(n);
    j[0] = 1;
    j[1] = 3;
    for (int i = 2; i < n; ++i) {
        j[i] = j[i - 2] + 2 * j[i - 1];
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

void sortLeft(Stack* to_sort, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++)
			if (to_sort[i].left > to_sort[j].left)
				std::swap(to_sort[i], to_sort[j]);
	}
}

// Implementación de customUpperBound para buscar en un rango específico de la cadena
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

    // Construir la main-chain inicial con los valores `a`
    for (int i = 0; i < mid; i++) {
        chain.push_back(to_sort[i].left);
    }

    // Insertar los valores `b` en el orden de Jacobsthal
    for (int i = 0; i < mid; i++) {
        int b_value = to_sort[i].right;

        // Calcula el rango hasta donde insertar usando el número de Jacobsthal
        int limit = (j_numbers[i] < static_cast<int>(chain.size())) ? j_numbers[i] : static_cast<int>(chain.size());

        // Usar customUpperBound para buscar la posición de inserción para `b_value`
        int insert_pos = customUpperBound(chain, 0, limit, b_value);

        // Insertar el valor `b` en la posición encontrada
        chain.insert(chain.begin() + insert_pos, b_value);
    }
}

void algo(char **nums, int argc) {

	//	0. Stacks

	std::deque<int> stack = getInp(nums, argc);
	std::deque<int> chain;

	//	1. Pair swaping

	stack = pairSwap(stack);

	std::cout << "Pair Swap" << std::endl;
	for (int i = 0; i < int(stack.size()); i++) {
		std::cout << stack[i] << "; ";
	}
	std::cout << std::endl;

	//	2. Creamos las dos chains, en una struct "STACK". Izquierda y derecha

	Stack *to_sort = new Stack[stack.size() / 2];

	for (int i = 0; i < int(stack.size() / 2); i++) {
		to_sort[i].left = stack[ i * 2 ];
		to_sort[i].right = stack[ i * 2 + 1 ];
	}

	std::cout << "Stack" << std::endl;
	for (int i = 0; i < int(stack.size() / 2); i++) {
		std::cout << "[" << to_sort[i].left << ", " << to_sort[i].right << "] ";
	}
	std::cout << std::endl;

	//	3. Sortear el stack izquierdo "A1".

	sortLeft(to_sort, stack.size() / 2);

	std::cout << "Sorted A1" << std::endl;
	for (int i = 0; i < int(stack.size() / 2); i++) {
		std::cout << "[" << to_sort[i].left << ", " << to_sort[i].right << "] ";
	}
	std::cout << std::endl;

	//	4. Insertion order using Jacobsthal numbers

	std::vector<int> j_numbers = jacobsthal(stack.size());
	
	insertWithJacobsthal(chain, to_sort, stack.size() / 2);
	std::cout << "Final Chain" << std::endl;
    for (int i = 0; i < int(chain.size()); i++) {
        std::cout << chain[i] << "; ";
    }
    std::cout << std::endl;
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
