/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_Stack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:15:46 by aaespino          #+#    #+#             */
/*   Updated: 2024/11/20 15:26:30 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

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

std::deque<int> getInp(char **nums, int argc) {
	
	std::deque<int> main;

	for (int i = 1; i < argc; i++) {
		main.push_back(atoi(nums[ i ]));
	}

	return main;
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
