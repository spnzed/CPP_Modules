/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:07:03 by aaespino          #+#    #+#             */
/*   Updated: 2024/10/17 17:24:26 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>

#include "../inc/RPN.hpp"

int cmp_inp(std::string str) {
    for (int i = 0; i < str.size() ; i++) {
        if (!isspace(str[i]) || !(str[i] == '+' || str[i] == '-' 
            || str[i] == '/' || str[i] == '*')) {
            if (!isdigit(str[i]))
                return 1;
            if (isdigit(str[i]) && isdigit(str[i + 1]))
                return 1;
        }
    }
    return 0;
}

void tokenizer(std::string str, std::deque<node> *stack) {
    for (int i = 0; i < str.size() ; i++) {
        node* tmp = NULL;
        if (!isspace(str[i])) {
            if (isdigit(str[i])) {
                tmp->_content = str[i];
                tmp->_type = "NUM";
                stack->push_back(*tmp);
            } else {
                tmp->_content = str[i];
                tmp->_type = "OPE";
                stack->push_back(*tmp);
            }
        }
        delete tmp;
    }
}

int addition(int f, int s) {
    return (f + s);
}

int subtraction(int f, int s) {
    return (f - s);
}

int multiplication(int f, int s) {
    return (f * s);
}

int division(int f, int s) {
    return (f / s);
}

int do_oper(std::deque<node> *stack) {
    for (std::size_t i = 0; i < stack.size(); ++i) {
        std::cout << stack[i] << " ";
    }
}

int main (int argc, char **argv) {

    std::deque<node> stack;
    
    if (argc == 2) {
        int res = 0;
    
        if (cmp_inp(argv[1])) {
            std::cout << "Error" << std::endl;
            return 1;
        } else {
            tokenizer(argv[1], &stack);
            res = do_oper(&stack);
            std::cout << res << std::endl;
        }
    } else {
        std::cout << "Error: invalid input." << std::endl;
    }
    
    return 0;
}
