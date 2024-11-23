/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_Stack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:15:46 by aaespino          #+#    #+#             */
/*   Updated: 2024/11/23 18:36:20 by aaespino         ###   ########.fr       */
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

    if (!name.empty()) {
        std::cout << BOLD << name << ". Size: " << size << RESET << std::endl;
    } else {
        std::cout << BOLD << "Size: " << size << RESET << std::endl;
    }

    if (size < 0) {
        std::cerr << RED << "Size cannot be negative." << RESET << std::endl;
        return;
    }

    int count = 0;
    int blockIndex = 1;
    bool newGroup = true;

    for (std::deque<int>::const_iterator it = stack.begin(); it != stack.end(); ++it) {
        if (newGroup) {
            if (name == "Full Stack" && blockIndex == 5) {
                std::cout << MAGENTA << "[";
            } else {
                std::cout << BLUE << "[";
            }
            newGroup = false;
        }

        std::deque<int>::const_iterator nextIt = it;
        ++nextIt;
        if (name == "Full Stack" && blockIndex == 5 && (count + 1 == size || nextIt == stack.end())) {
            std::cout << HIGHLIGHT << *it << RESET;
        } else {
            std::cout << GREEN << *it << RESET;
        }

        ++count;

        if (count == size || nextIt == stack.end()) {
            if (name == "Full Stack" && blockIndex == 5) {
                std::cout << MAGENTA << "] " << RESET;
            } else {
                std::cout << BLUE << "] " << RESET;
            }
            count = 0;
            newGroup = true;
            ++blockIndex;
        } else {
            std::cout << YELLOW << ", " << RESET;
        }
    }

    std::cout << std::endl;
}

void printToSort(const Stack_node* to_sort, int size) {
    std::cout << "Contents of to_sort:" << std::endl;
    for (const Stack_node* it = to_sort; it < to_sort + size; ++it) {
        std::cout << "Left: " << it->left << ", Right: " << it->right << std::endl;
    }
}
