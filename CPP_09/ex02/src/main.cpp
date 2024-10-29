/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:18:31 by aaespino          #+#    #+#             */
/*   Updated: 2024/10/29 19:00:08 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

#include <deque>
#include <vector>
#include <cstdlib>

int compArgs(char **argv, int argc) {

	for (int i = 1; i < argc; i++) {
		try {
			int num = atoi(argv[i]);

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

std::deque<int> pairCmp(std::deque<int> input) {

	for (int i = 0; i < int(input.size() / 2); i++) {
		if (input[ i * 2 + 1 ] < input[ i * 2 ])
			std::swap(input[ i * 2 ], input[ i * 2 + 1]);
	}

	return input;
}

std::deque<int> mergeStk (std::deque<int> left, std::deque<int> right) {
	std::deque<int> ret;

	while (!left.empty() && !right.empty()) {
		if (left.front() < right.front()) {
			ret.push_back(left.front());
			left.pop_front();
		} else {
			ret.push_back(right.front());
			right.pop_front();
		}
	}
	
	while (!left.empty()) {
		ret.push_back(left.front());
		left.pop_front();
	}

	while (!right.empty()) {
		ret.push_back(right.front());
		right.pop_front();
	}

	for (int i = 0; i < int(ret.size()); i++) {
		std::cout << ret[i] << "; ";
	}
	std::cout << std::endl;

	return ret;
}

std::deque<int> sortMerge (std::deque<int> stk) {

	if (stk.size() <= 1) {
		return stk;
	}
	
	std::deque<int> first(stk.begin(), stk.begin() + (stk.size() / 2));
	std::deque<int> left = sortMerge(first);
	std::deque<int> second(stk.begin() + (stk.size() / 2), stk.end());
	std::deque<int> right = sortMerge(second);

	return (mergeStk(left, right));
}

void algo(char **nums, int argc) {

	std::deque<int> stack = getInp(nums, argc);
	std::deque<int> s_stack1;
	std::deque<int> s_stack2;

	stack = pairCmp(stack);

	for (int i = 0; i < int(stack.size()); i++) {
		std::cout << stack[i] << "; ";
	}
	std::cout << std::endl;

	for (int i = 0; i < int(stack.size() / 2); i++) {
		s_stack1.push_back(stack[ i * 2 ]);
		s_stack2.push_back(stack[ i * 2 + 1 ]);
	}

	s_stack1 = sortMerge(s_stack1);
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
