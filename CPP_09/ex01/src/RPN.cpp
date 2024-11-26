/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:07:47 by aaespino          #+#    #+#             */
/*   Updated: 2024/11/26 18:18:50 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

RPN::RPN(void) {
}

RPN::RPN(std::string const &input) : _input(input), _stack() {
}

RPN::~RPN(void) {
}

RPN::RPN(RPN const &a) {
	*this = a;
}

RPN &RPN::operator=(RPN const &a){

	if ( this != &a ) {
		this->_input = a._input;
		this->_stack = a._stack;
	}
 	return *this;
}

std::ostream& operator<<(std::ostream& os, const node& n) {
    os << n._content << " (" << n._type << ")";
    return os;
}

void RPN::calculateRPN(void) {
	this->compInput();
    this->tokenizer();
    this->doRPN();
}

void RPN::compInput(void) {
    for (unsigned int i = 0; i < this->_input.size(); i++) {
        if (!isspace(this->_input[i]) && !(this->_input[i] == '+' || this->_input[i] == '-' 
            || this->_input[i] == '/' || this->_input[i] == '*')) {
            if (!isdigit(this->_input[i])) {
                throw std::runtime_error("Character is neither a number nor a valid operator.");
            }
            if (isdigit(this->_input[i]) && i + 1 < this->_input.size() && isdigit(this->_input[i + 1])) {
                throw std::runtime_error("Only single-digit numbers are allowed.");
            }
        }
    }
}

void RPN::tokenizer(void) {
    for (unsigned int i = 0; i < this->_input.size() ; i++) {
        node tmp;
        if (!isspace(this->_input[i])) {
            if (isdigit(this->_input[i])) {
                tmp._content = this->_input[i];
                tmp._type = "NUM";
            } else {
                tmp._content = this->_input[i];
                tmp._type = "OPE";
            }
            this->_stack.push_back(tmp);  // push_back es compatible con list
        }
    }
}

void RPN::doRPN(void) {
    std::list<int> nums;

    for (std::list<node>::iterator it = this->_stack.begin(); it != this->_stack.end(); ++it) {
        if (it->_type == "NUM") {
            node tmp = *it;
            nums.push_back(tmp._content - '0');
        } else {
            if (nums.size() < 2) {
                throw std::runtime_error("Not enough operators");
            } else {
                int s = nums.back(); nums.pop_back();
                int f = nums.back(); nums.pop_back();

                int res = 0;
                try {
                    res = doOperation(f, s, it->_content);
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

    std::cout << nums.back() << std::endl;;
}

int RPN::addition(int f, int s) {
    return (f + s);
}

int RPN::subtraction(int f, int s) {
    return (f - s);
}

int RPN::multiplication(int f, int s) {
    return (f * s);
}

int RPN::division(int f, int s) {
    return (f / s);
}

int RPN::doOperation(int f, int s, char op) {
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

template <typename T>
void RPN::printList(const std::list<T> &list) {
    std::cout << "[";
    for (typename std::list<T>::const_iterator it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "]" << std::endl;
}
