/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:07:47 by aaespino          #+#    #+#             */
/*   Updated: 2024/12/11 16:28:19 by aaespino         ###   ########.fr       */
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
	std::list<long double> nums;

	for (std::list<node>::iterator it = this->_stack.begin(); it != this->_stack.end(); ++it) {
		if (it->_type == "NUM") {
			node tmp = *it;
			nums.push_back(tmp._content - '0');
		} else {
			if (nums.size() < 2) {
				throw std::runtime_error("Not enough operators");
			} else {
				long double s = nums.back(); nums.pop_back();
				long double f = nums.back(); nums.pop_back();

				long double res = 0;
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
	std::cout << std::fixed << std::setprecision(2) << nums.back() << std::endl;
}

bool	RPN::infiniteCheck(long double n) {
	if (std::isinf(n)) {
		if (std::signbit(n))
			throw std::runtime_error("Negative infinity encountered.");
		else
			throw std::runtime_error("Positive infinity encountered.");
	}
	return true;
}

bool	RPN::additionCheck(long double n1, long double n2) {
	if (n1 > 0 && n2 > 0 && n1 > (std::numeric_limits<int>::max() - n2))
		throw std::runtime_error("Overflow: addition result is too big.");
	if (n1 < 0 && n2 < 0 && n1 < (std::numeric_limits<int>::min() - n2))
		throw std::runtime_error("Underflow: addition result is too small.");
	return true;
}

bool	RPN::subtractionCheck(long double n1, long double n2) {
	if (n1 > 0 && n2 < 0 && n1 > (std::numeric_limits<int>::max() + n2))
		throw std::runtime_error("Overflow: subtraction result is too big.");
	if (n1 < 0 && n2 > 0 && n1 < (std::numeric_limits<int>::min() + n2))
		throw std::runtime_error("Underflow: subtraction result is too small.");
	return true;
}

bool	RPN::multiplicationCheck(long double n1, long double n2) {
	long double res = n1 * n2;
	if (!infiniteCheck(res))
		return false;
	if (n1 > 0 && n2 > 0 && n1 > (std::numeric_limits<int>::max() / n2))
		throw std::runtime_error("Overflow: multiplication result is too big.");
	else if (n1 < 0 && n2 < 0 && n1 < (std::numeric_limits<int>::max() / n2))
		throw std::runtime_error("Overflow: multiplication result is too big.");
	else if (n1 > 0 && n2 < 0 && n1 < (std::numeric_limits<int>::min() / 2))
		throw std::runtime_error("Underflow: multiplication result is too small.");
	else if (n1 < 0 && n2 > 0 && n1 < (std::numeric_limits<int>::min() / 2))
		throw std::runtime_error("Underflow: multiplication result is too small.");

	return true;
}

bool	RPN::divisionCheck(long double n1, long double n2) {
	if (n2 == 0)
		throw std::runtime_error("Division by zero.");
	if (!infiniteCheck(n1 / n2))
		return false;

	if (n1 > 0 && n2 > 0 && n1 > (std::numeric_limits<int>::max() / n2))
        throw std::runtime_error("Overflow: division result is too big.");
	else if (n1 < 0 && n2 < 0 && n1 < (std::numeric_limits<int>::max() / n2))
        throw std::runtime_error("Overflow: division result is too big.");
	else if (n1 > 0 && n2 < 0 && n1 < (std::numeric_limits<int>::min() / n2))
        throw std::runtime_error("Underflow: division result is too small.");
	else if (n1 < 0 && n2 > 0 && n1 < (std::numeric_limits<int>::min() / n2))
        throw std::runtime_error("Underflow: division result is too small.");

	return true;
}

long double RPN::addition(long double f, long double s) {
	if (!additionCheck(f, s))
		throw std::runtime_error("Addition error: out of bounds.");
	return f + s;
}

long double RPN::subtraction(long double f, long double s) {
	if (!subtractionCheck(f, s))
		throw std::runtime_error("Subtraction error: out of bounds.");
	return f - s;
}

long double RPN::multiplication(long double f, long double s) {
	if (!multiplicationCheck(f, s))
		throw std::runtime_error("Multiplication error: out of bounds.");
	return f * s;
}

long double RPN::division(long double f, long double s) {
	if (!divisionCheck(f, s))
		throw std::runtime_error("Division error: out of bounds.");
	return f / s;
}

long double RPN::doOperation(long double f, long double s, char op) {
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
