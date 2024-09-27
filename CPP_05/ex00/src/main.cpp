/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:31:13 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/27 16:35:00 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include <iostream>

int main() {
    // 1. Create a bureaucrat with a valid grade
    std::cout << "\033[34m" << "1. Creating a bureaucrat with a valid grade: " << "\033[0m" << std::endl;
    Bureaucrat b1("Alice", 2);
    std::cout << b1 << std::endl;

    // 2. Attempt to increment the grade (this should throw an exception)
    std::cout << "\033[33m" << "2. Trying to increment the grade (should throw an exception if the grade is too high): " << "\033[0m" << std::endl;
    b1.incGrade();  // El manejo de excepciones ahora está en setGrade
    std::cout << "\033[32m" << "After incrementing the grade: " << "\033[0m" << b1 << std::endl;

    // 3. Decrement the grade, which should work
    std::cout << "\033[34m" << "3. Decrementing the grade: " << "\033[0m" << std::endl;
    b1.decGrade();
    std::cout << "\033[32m" << "After decrementing the grade: " << "\033[0m" << b1 << std::endl;

    // 4. Create a bureaucrat with an invalid grade (below maximum)
    std::cout << "\033[31m" << "4. Creating a bureaucrat with an invalid grade (below maximum): " << "\033[0m" << std::endl;
    Bureaucrat b2("Bob", 0);  // Maneja la excepción en setGrade
    std::cout << b2 << std::endl;

    // 5. Create a bureaucrat with an invalid grade (above minimum)
    std::cout << "\033[31m" << "5. Creating a bureaucrat with an invalid grade (above minimum): " << "\033[0m" << std::endl;
    Bureaucrat b3("Charlie", 151);  // Maneja la excepción en setGrade
    std::cout << b3 << std::endl;

    return 0;
}
