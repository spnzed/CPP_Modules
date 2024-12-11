/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:07:46 by aaespino          #+#    #+#             */
/*   Updated: 2024/12/11 15:34:15 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <list>
#include <limits>
#include <iomanip>
#include <cmath>  // Para std::isnan y std::isinf
#include <stdexcept>  // Para std::runtime_error

struct node {
    char            _content;
    std::string     _type;
};

class RPN
{
    public:
        std::string     _input;
        std::list<node> _stack;

        RPN(void);
        RPN(std::string const &input);
        ~RPN(void);
        RPN(RPN const &a);
        RPN &operator=(RPN const &a);

        void calculateRPN(void);

    private:

        // Validación y tokenización
        void compInput(void);
        void tokenizer(void);

        // Cálculo del RPN
        void doRPN(void);

        // Operaciones matemáticas
        long double addition(long double f, long double s);
        long double subtraction(long double f, long double s);
        long double multiplication(long double f, long double s);
        long double division(long double f, long double s);
        long double doOperation(long double f, long double s, char op);

        bool	infiniteCheck(long double n);
        bool	additionCheck(long double n1, long double n2);
        bool	subtractionCheck(long double n1, long double n2);
        bool	multiplicationCheck(long double n1, long double n2);
        bool	divisionCheck(long double n1, long double n2);

        // Mostrar pila (opcional para depuración)
        template <typename T>
        void printList(const std::list<T>& list);
};

std::ostream& operator<<(std::ostream& os, const node& n);

#endif
