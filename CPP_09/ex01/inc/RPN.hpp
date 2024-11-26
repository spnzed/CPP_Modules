/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:07:46 by aaespino          #+#    #+#             */
/*   Updated: 2024/11/26 18:01:43 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <list>

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
        int addition(int f, int s);
        int subtraction(int f, int s);
        int multiplication(int f, int s);
        int division(int f, int s);
        int doOperation(int f, int s, char op);

        // Mostrar pila (opcional para depuración)
        template <typename T>
        void printList(const std::list<T>& list);
};

std::ostream& operator<<(std::ostream& os, const node& n);

#endif
