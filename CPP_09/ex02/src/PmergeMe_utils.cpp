/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe_utils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:29:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/11/19 18:40:33 by aaespino         ###   ########.fr       */
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
#define HIGHLIGHT "\033[1;41m" // Fondo rojo con texto en negrita
#define MAGENTA "\033[35m"


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

int binarySearch(const std::deque<int>& chain, int start, int end, int value) {
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
        std::cout << BOLD << name << ". Size: " << size << RESET << std::endl;
    } else {
        std::cout << BOLD << "Size: " << size << RESET << std::endl;
    }

    if (size < 0) {
        std::cerr << RED << "Size cannot be negative." << RESET << std::endl;
        return;
    }

    int count = 0;       // Contador dentro del grupo actual
    int blockIndex = 1;  // Índice del bloque actual
    bool newGroup = true;

    for (std::deque<int>::const_iterator it = stack.begin(); it != stack.end(); ++it) {
        if (newGroup) {
            if (name == "Full Stack" && blockIndex == 5) {
                std::cout << MAGENTA << "["; // Bloque 5 en magenta
            } else {
                std::cout << BLUE << "["; // Otros bloques en azul
            }
            newGroup = false;
        }

        // Verificar si es el último número del quinto bloque (solo para "Full Stack")
        std::deque<int>::const_iterator nextIt = it;
        ++nextIt; // Avanzar manualmente el iterador
        if (name == "Full Stack" && blockIndex == 5 && (count + 1 == size || nextIt == stack.end())) {
            std::cout << HIGHLIGHT << *it << RESET; // Último número llamativo
        } else {
            std::cout << GREEN << *it << RESET; // Otros números en verde
        }

        ++count;

        // Determina si cerrar el grupo actual
        if (count == size || nextIt == stack.end()) {
            if (name == "Full Stack" && blockIndex == 5) {
                std::cout << MAGENTA << "] " << RESET; // Cierra el quinto bloque en magenta
            } else {
                std::cout << BLUE << "] " << RESET; // Cierra otros bloques en azul
            }
            count = 0; // Reinicia el contador
            newGroup = true;
            ++blockIndex; // Incrementa el índice del bloque
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
