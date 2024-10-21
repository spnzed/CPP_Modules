/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:25:41 by aaespino          #+#    #+#             */
/*   Updated: 2024/10/21 15:36:30 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Span {
    private:
        std::vector<int>	_total_span;
        unsigned int		_limit;
        unsigned int		_total_added;
    public:
        Span(void);
        Span(unsigned int N);
        Span(const Span &a);
        ~Span(void);
        Span &operator=(const Span &a);
    
        void addNumber(unsigned int);
        void addManyNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        unsigned int shortestSpan(void);
        unsigned int longestSpan(void);

        void showSpan(void);
};

#endif
