/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe_utils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:29:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/11/18 19:24:07 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Códigos ANSI para colores
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"

#include <iostream>
#include <deque>
#include <vector>
#include <cstdlib>

struct Stack_node {
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


void printDeque(const std::deque<int>& stack, int size, const std::string& name) {
    // Título de la pila
    if (!name.empty()) {
        
        if (size > 0) {
            std::cout << BOLD << name << ". Size: " << size << RESET << std::endl;
        } else if (size == 0) {
            std::cout << BOLD << name << ". Size: " << size + 1 << RESET << std::endl;
        }
    } else {
        std::cout << BOLD << "Size: " << size << RESET << std::endl;
    }

    if (size < 0) {
        std::cerr << RED << "Size cannot be negative." << RESET << std::endl;
        return;
    }

    int count = 0; // Contador dentro del grupo actual
    bool newGroup = true;

    for (std::deque<int>::const_iterator it = stack.begin(); it != stack.end(); ++it) {
        if (newGroup) {
            std::cout << BLUE << "[" << RESET; // Abre un nuevo grupo con color azul
            newGroup = false;
        }

        std::cout << GREEN << *it << RESET; // Elementos del grupo en verde
        ++count;

        // Determina si cerrar el grupo actual
        std::deque<int>::const_iterator nextIt = it;
        ++nextIt;
        if (count == size || nextIt == stack.end()) {
            std::cout << BLUE << "] " << RESET; // Cierra el grupo con azul
            count = 0; // Reinicia el contador
            newGroup = true;
        } else {
            std::cout << YELLOW << ", " << RESET; // Separador en amarillo
        }
    }

    std::cout << std::endl; // Salto de línea al final para mejorar legibilidad
}

void printToSort(const Stack_node* to_sort, int size) {
    std::cout << "Contents of to_sort:" << std::endl;
    for (const Stack_node* it = to_sort; it < to_sort + size; ++it) {
        std::cout << "Left: " << it->left << ", Right: " << it->right << std::endl;
    }
}

// std::deque<int> pairSwap(std::deque<int> input) {

// 	for (int i = 0; i < int(input.size() / 2); i++) {
// 		if (input[ i * 2 + 1 ] < input[ i * 2 ])
// 			std::swap(input[ i * 2 ], input[ i * 2 + 1]);
// 	}

// 	return input;
// }
