/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:58:29 by aaronespino       #+#    #+#             */
/*   Updated: 2024/11/26 14:58:31 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <list>  // Cambiado a list

#include "../inc/RPN.hpp"

void cmp_inp(std::string str) {
    for (unsigned int i = 0; i < str.size(); i++) {
        if (!isspace(str[i]) && !(str[i] == '+' || str[i] == '-' 
            || str[i] == '/' || str[i] == '*')) {
            if (!isdigit(str[i])) {
                throw std::runtime_error("Character is neither a number nor a valid operator.");
            }
            if (isdigit(str[i]) && i + 1 < str.size() && isdigit(str[i + 1])) {
                throw std::runtime_error("Only single-digit numbers are allowed.");
            }
        }
    }
}

void tokenizer(std::string str, std::list<node> *stack) {  // Cambiado a list
    for (unsigned int i = 0; i < str.size() ; i++) {
        node tmp;
        if (!isspace(str[i])) {
            if (isdigit(str[i])) {
                tmp._content = str[i];
                tmp._type = "NUM";
            } else {
                tmp._content = str[i];
                tmp._type = "OPE";
            }
            stack->push_back(tmp);  // push_back es compatible con list
        }
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

template <typename T>
void show_stack(const std::list<T> &stack) {  // Cambiado a list
    std::cout << "[";
    for (typename std::list<T>::const_iterator it = stack.begin(); it != stack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "]" << std::endl;
}

int do_opr(int f, int s, char op) {
    switch (op) {
        case '+': return addition(f, s);
        case '-': return subtraction(f, s);
        case '*': return multiplication(f, s);
        case '/':
            if (s == 0)
                throw std::runtime_error("Division 0");
            return division(f, s);
        default:
            throw std::runtime_error("No operator");
    }
}

int do_rpn(std::list<node> &stack) {  // Cambiado a list
    std::list<int> nums;

    for (std::list<node>::iterator it = stack.begin(); it != stack.end(); ++it) {
        if (it->_type == "NUM") {
            node tmp = *it;
            nums.push_back(tmp._content - '0');
        } else {
            if (nums.size() < 2) {
                throw std::runtime_error("Not enough numbers");
            } else {
                int s = nums.back(); nums.pop_back();
                int f = nums.back(); nums.pop_back();

                int res = 0;
                try {
                    res = do_opr(f, s, it->_content);
                } catch (std::runtime_error &e) {
                    throw std::runtime_error(e);
                }

                nums.push_back(res);
            }
        }
    }

    if (nums.size() != 1) {
        throw std::runtime_error("Not enough operators");
    }

    return nums.back();
}

int main (int argc, char **argv) {
    std::list<node> stack;  // Cambiado a list

    if (argc == 2) {
        int res = 0;
        try {
            cmp_inp(argv[1]);
            tokenizer(argv[1], &stack);
            res = do_rpn(stack);
            std::cout << res << std::endl;
        } catch (std::runtime_error &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    } else {
        std::cout << "Error: Invalid input." << std::endl;
    }

    return 0;
}
