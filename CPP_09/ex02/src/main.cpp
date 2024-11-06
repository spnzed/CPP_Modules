/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:18:31 by aaespino          #+#    #+#             */
/*   Updated: 2024/11/06 17:19:18 by aaronespino      ###   ########.fr       */
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
    if (n > 0) j[0] = 0 * 2; // J(0) = 0
    if (n > 1) j[1] = 1 * 2; // J(1) = 1
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

void sortRight(Stack* to_sort, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++)
			if (to_sort[i].right > to_sort[j].right)
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

    // std::cout << MAGENTA << "JacobSthal" << std::endl;
	// for (std::vector<int>::iterator it = j_numbers.begin(); it != j_numbers.end(); ++it) {
    //     std::cout << *it << " ";
    // }
    // std::cout << RESET << std::endl;

    // Construir la main-chain inicial con los valores `a`
    for (int i = 0; i < mid; i++) {
        chain.push_back(to_sort[i].right);
    }

	// std::cout << int(chain.size()) << std::endl;

    // std::cout << BLUE << "Deque Chain" << std::endl;
    // for (std::deque<int>::iterator it = chain.begin(); it != chain.end(); ++it) {
    //     std::cout << *it << " ";
    // }
    // std::cout << RESET << std::endl;

    // std::cout << RED << "Deque to Insert" << std::endl;
	// for (int i = 0; i < mid; i++) {
    //     std::cout << to_sort[i].left << " ";
    // }
    // std::cout << RESET << std::endl;

	chain.push_front(to_sort[0].left);

	// std::cout << "After pushing def" << std::endl;
    // for (std::deque<int>::iterator it = chain.begin(); it != chain.end(); ++it) {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;

    // Insertar los valores `b` en el orden de Jacobsthal
	int prev = 0;
	int limit = 0;

	// std::cout << "Mid " << mid << std::endl;
    for (int i = 1; i < mid; i++) {
	
        // Calcula el rango de numeros que insertaremos de B1->A1
        if (j_numbers[i] <= mid)
			limit += j_numbers[i];

        if (limit > mid)
			limit = mid - 1;

		//	Insertamos todo lo de
		for (int j = limit; j > prev && j <= mid; j--) {

			// std::cout << std::endl;
			// std::cout << j << " >= " << prev << " && " << j << " < " << mid << std::endl;
			// std::cout << "ʌ" << "    " << "ʌ" << "    " << "ʌ" << std::endl;
			// std::cout << "|" << "    " << "|" << "    " << "|" << std::endl;
			// std::cout << "j" << "  " << "prev" << "   " << "j" << std::endl;
			// std::cout << std::endl;
			int b_value = to_sort[j].left;
			int insert_pos = customUpperBound(chain, 0, int(chain.size()), b_value);
			// std::cout << "From " << YELLOW << prev << RESET ;
			// std::cout << " to " << GREEN << limit << RESET << std::endl;
			// std::cout << "Jacob 'i' " << YELLOW << "[" << i << "]" << RESET ;
			// std::cout << " deque to insert 'j' " << GREEN << "[" << j << "]" << RESET << std::endl;
			// std::cout << "Inserting " << b_value << " at position " << insert_pos << std::endl;
			chain.insert(chain.begin() + insert_pos, b_value);

			// std::cout << BLUE << "Deque Chain after insertion of: " << RED << b_value << BLUE << std::endl;
			// for (std::deque<int>::iterator it = chain.begin(); it != chain.end(); ++it) {
			// 	std::cout << *it << " ";
			// }
			// std::cout << RESET << std::endl;

			if (j - 1 == prev) {
				prev = limit;
			}
			
		}
    }
}

void algo(char **nums, int argc) {

	//	0. Stacks

	std::deque<int> stack = getInp(nums, argc);
	std::deque<int> chain;

	//	1. Pair swaping

	stack = pairSwap(stack);

	// std::cout << "Pair Swap" << std::endl;
	// for (int i = 0; i < int(stack.size()); i++) {
	// 	std::cout << stack[i] << "; ";
	// }
	// std::cout << std::endl;

	//	2. Creamos las dos chains, en una struct "STACK". Izquierda y derecha

	Stack *to_sort = new Stack[stack.size() / 2];

	for (int i = 0; i < int(stack.size() / 2); i++) {
		to_sort[i].left = stack[ i * 2 ];
		to_sort[i].right = stack[ i * 2 + 1 ];
	}

	// std::cout << "Stack" << std::endl;
	// for (int i = 0; i < int(stack.size() / 2); i++) {
	// 	std::cout << "[" << to_sort[i].left << ", " << to_sort[i].right << "] ";
	// }
	// std::cout << std::endl;

	//	3. Sortear el stack izquierdo "A1".

	sortRight(to_sort, stack.size() / 2);

	// std::cout << "Sorted A1" << std::endl;
	// for (int i = 0; i < int(stack.size() / 2); i++) {
	// 	std::cout << "[" << to_sort[i].left << ", " << to_sort[i].right << "] ";
	// }
	// std::cout << std::endl;

	//	4. Insertion order using Jacobsthal numbers
	
	insertWithJacobsthal(chain, to_sort, stack.size() / 2);
	std::cout << "Final Chain" << std::endl;
    for (int i = 0; i < int(chain.size()); i++) {
        std::cout << chain[i] << "; ";
    }
    std::cout << std::endl;

	delete []to_sort;

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
