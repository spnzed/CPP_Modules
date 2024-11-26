/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:07:46 by aaespino          #+#    #+#             */
/*   Updated: 2024/11/26 18:34:48 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <iostream>
#include <string>
#include <algorithm>
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
#define HIGHLIGHT "\033[1;41m"

//--------------------------------------------------------------------------------------//

//                      MANIPULACION DE STACK
// Funciones relacionadas con la comprobación
int compArgs(char **argv, int argc);
int compRep(int target, char** set, int limit);

//--------------------------------------------------------------------------------------//

//                      DEQUE

// Funciones relacionadas con la manipulación de cadenas
std::deque<int> getDeque(char **nums, int argc);
std::deque<int> getStack(std::deque<int>& stack, int end, int group_size, int side);
// Funciones de impresión
void printDeque(const std::deque<int>& stack, int size, const std::string& name);
//                      ALGO DEQUE
int binarySearch(const std::deque<int>& chain, int end, int value, int size);
void insertWithJacobsthal(std::deque<int>& stack, int end, int group_size);
void msi(std::deque<int>& stack, int end, int size);

//--------------------------------------------------------------------------------------//

//                      VECTOR

// Funciones relacionadas con la manipulación de cadenas
std::vector<int> getVector(char **nums, int argc);
std::vector<int> getStack(std::vector<int>& stack, int end, int group_size, int side);
// Funciones de impresión
void printVector(const std::vector<int>& stack, int size, const std::string& name);
//                      ALGO VECTOR
int binarySearch(const std::vector<int>& chain, int end, int value, int size);
void insertWithJacobsthal(std::vector<int>& stack, int end, int group_size);
void msi(std::vector<int>& stack, int end, int size);

//--------------------------------------------------------------------------------------//

#endif
