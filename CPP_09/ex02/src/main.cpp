/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:18:31 by aaespino          #+#    #+#             */
/*   Updated: 2024/10/29 13:54:45 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

#include <deque>
#include <vector>

int comp_args(char **argv, int argc) {

	for (int i = 1; argv[i] != NULL; i++) {
		try {
			int num = std::stoi(argv[i]);

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

std::deque<int> get_inp(char **nums, int argc) {
	
	std::deque<int> main;

	for (int i = 1; i < argc; i++) {
		main.push_back(std::stoi(nums[ i ]));
	}

	return main;
}

std::deque<int> pair_cmp(std::deque<int> input) {

	for (int i = 0; i < input.size() / 2; i++) {
		if (input[ i * 2 + 1 ] < input[ i * 2 ])
			std::swap(input[ i * 2 ], input[ i * 2 + 1]);
	}

	return input;
}

void algo(char **nums, int argc) {

	std::deque<int> stack = get_inp(nums, argc);
	std::deque<int> s_stack1;
	std::deque<int> s_stack2;

	stack = pair_cmp(stack);

	for (int i = 0; i < stack.size() / 2; i++) {
		s_stack1.push_back(stack[ i * 2 ]);
		s_stack2.push_back(stack[ i * 2 + 1 ]);
	}
}

int main (int argc, char **argv) {

	if (argc <= 2) {
		std::cout << "Error: invalid input." << std::endl;
		return 1;
	} else {
		if (comp_args(argv, argc))
			algo(argv, argc);
	}
	return 0;
}
