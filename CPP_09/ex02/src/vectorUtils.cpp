/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorUtils.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:15:46 by aaespino          #+#    #+#             */
/*   Updated: 2024/11/23 18:36:20 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

std::vector<int> getStack(std::vector<int>& stack, int end, int group_size, int side) {
    std::vector<int> chain;

    if (group_size > 0) {
        if (side == 0) {
            std::vector< int >::iterator it = stack.begin();
            size_t pos = 0;
            while ( pos + group_size <= stack.size() ) {
                chain.insert( chain.end(), it + pos, it + pos + group_size );
                pos += group_size * 2;
            }
        } else {
            std::vector< int >::iterator it = stack.begin();
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

std::vector<int> getVector(char **nums, int argc) {
	
	std::vector<int> main;

	for (int i = 1; i < argc; i++) {
		main.push_back(atoi(nums[ i ]));
	}

	return main;
}

void printVector(const std::vector<int>& stack, int size, const std::string& name) {

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

    for (std::vector<int>::const_iterator it = stack.begin(); it != stack.end(); ++it) {
        if (newGroup) {
            if (name == "Full Stack" && blockIndex == 5) {
                std::cout << MAGENTA << "[";
            } else {
                std::cout << BLUE << "[";
            }
            newGroup = false;
        }

        std::vector<int>::const_iterator nextIt = it;
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
