/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:07:46 by aaespino          #+#    #+#             */
/*   Updated: 2024/11/23 18:41:01 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <iostream>
#include <string>
#include <algorithm>  // Necesario para std::find
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <vector>
#include <ctime>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define HIGHLIGHT "\033[1;41m" // Fondo rojo con texto en negrita

struct Stack_node {
    int left;
    int right;
};

struct Stack {
    std::vector<Stack_node> left;
    std::vector<Stack_node> right;
};

//                      MANIPULACION DE STACK
// Funciones relacionadas con la comparación
int compArgs(char **argv, int argc);
int compRep(int target, char** set, int limit);

//                      DEQUE

// Funciones relacionadas con la manipulación de cadenas
std::deque<int> getDeque(char **nums, int argc);
std::deque<int> getStack(std::deque<int>& stack, int end, int group_size, int side);
// Funciones de impresión
void printDeque(const std::deque<int>& stack, int size, const std::string& name);
void printToSort(const Stack_node* to_sort, int size);

//                      ALGO
// binary_search.cpp
int littleBinarySearch(const std::deque<int>& chain, int end, int value);
int binarySearch(const std::deque<int>& chain, int end, int value, int size);
// jacobsthal.cpp
void insertWithJacobsthal(std::deque<int>& stack, int end, int group_size);
// msi.cpp
void msi(std::deque<int>& stack, int end, int size);

//                      DEQUE

// Funciones relacionadas con la manipulación de cadenas
std::vector<int> getVector(char **nums, int argc);
std::vector<int> getStack(std::vector<int>& stack, int end, int group_size, int side);
// Funciones de impresión
void printVector(const std::vector<int>& stack, int size, const std::string& name);
void printToSort(const Stack_node* to_sort, int size);

//                      ALGO
// binary_search.cpp
int littleBinarySearch(const std::vector<int>& chain, int end, int value);
int binarySearch(const std::vector<int>& chain, int end, int value, int size);
// jacobsthal.cpp
void insertWithJacobsthal(std::vector<int>& stack, int end, int group_size);
// msi.cpp
void msi(std::vector<int>& stack, int end, int size);

#endif
