/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:07:03 by aaespino          #+#    #+#             */
/*   Updated: 2024/10/21 19:16:38 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>

#include "../inc/RPN.hpp"

int cmp_inp(std::string str) {
    for (unsigned int i = 0; i < str.size() ; i++) {
        if (!isspace(str[i]) && !(str[i] == '+' || str[i] == '-' 
            || str[i] == '/' || str[i] == '*')) {
            if (!isdigit(str[i]))
                return 1;
            if (isdigit(str[i]) && isdigit(str[i + 1]))
                return 1;
            if (i + 1 < str.size() && isdigit(str[i]) && isdigit(str[i + 1]))
                return 1;
        }
    }
    return 0;
}

void tokenizer(std::string str, std::deque<node> *stack) {
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
            stack->push_back(tmp);
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
void show_stack(const std::deque<T> &stack) {
    std::cout << "[";
    for (typename std::deque<T>::const_iterator it = stack.begin(); it != stack.end(); ++it) {
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

int do_rnp(std::deque<node> &stack) {

    std::deque<int> nums;

    for (std::deque<node>::iterator it = stack.begin(); it != stack.end(); ++it) {
        if (it->_type == "NUM") {
            node tmp = *it;
            nums.push_back(tmp._content - '0');
            // it = stack.erase(it);
        } else {
            if (nums.size() < 2) {
                throw std::runtime_error("Not enough numbers");
            } else {
                int s = nums.back(); nums.pop_back();
                int f = nums.back(); nums.pop_back();
                
                int res = do_opr(f, s, it->_content);

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

    std::deque<node> stack;
    
    if (argc == 2) {
        int res = 0;
    
        if (cmp_inp(argv[1])) {
            std::cout << "Error" << std::endl;
            return 1;
        } else {
            try {
                tokenizer(argv[1], &stack);
                res = do_rnp(stack);
                std::cout << res << std::endl;
            } catch (std::runtime_error &e) {
                std::cerr << e.what() << std::endl;
            }
        }
    } else {
        std::cout << "Error: invalid input." << std::endl;
    }
    
    return 0;
}
