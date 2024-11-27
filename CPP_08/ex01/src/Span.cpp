/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:16:48 by aaespino          #+#    #+#             */
/*   Updated: 2024/11/27 23:10:50 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>


Span::Span(void) : _limit(0), _total_added(0) {
}

Span::Span(unsigned int N) : _limit(N), _total_added(0) {
}

Span::Span(const Span &a) {
    *this = a;
}

Span::~Span(void) {
}

Span& Span::operator=(const Span &a) {
    if (this != &a) {
        this->_limit = a._limit;
        this->_total_span = a._total_span;
        this->_total_added = a._total_added;
    }
    return *this;
}

void Span::addNumber(unsigned int n) {
    unsigned int tmp = this->_total_added + 1;
    if (tmp > this->_limit) {
        throw std::exception();
    } else {
        this->_total_added++;
        this->_total_span.push_back(n);
    }
}

void Span::addManyNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (this->_total_added + std::distance(begin, end) > this->_limit) {
        throw std::exception();
    } else {
        this->_total_span.insert(this->_total_span.begin(), begin, end);
        this->_total_added += std::distance(begin, end);
    }
}

unsigned int Span::shortestSpan(void) {
    std::vector<int> tmp = this->_total_span;
    
    if (tmp.size() < 2) {
        throw std::exception();
    }

    std::sort(tmp.begin(), tmp.end());    
    std::vector<int> diff(tmp.size());
    std::adjacent_difference(tmp.begin(), tmp.end(), diff.begin());

    return *std::min_element(diff.begin() + 1, diff.end());
}

unsigned int Span::longestSpan(void) {
    std::vector<int> tmp = this->_total_span;

    if (tmp.size() < 2) {
        throw std::exception();
    }

    std::sort(tmp.begin(), tmp.end());

    int span = *(tmp.end() - 1) - *tmp.begin();

    return span;   
}

void    Span::showSpan(void) {
    std::vector<int> tmp = this->_total_span;

    std::sort(tmp.begin(), tmp.end());

    std::vector<int>::iterator it;

    std::cout << "Span Content: " << std::endl;

    for (it = tmp.begin(); it != tmp.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}