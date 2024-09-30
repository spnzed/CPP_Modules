/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:37:32 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/30 17:13:51 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    // 1. Create Bureaucrats
    std::cout << "\033[31m" << "1. Creating Bureaucrats: " << "\033[0m" << std::endl;
    Bureaucrat alice("Alice", 1);  // High-grade bureaucrat, can sign and execute everything
    Bureaucrat bob("Bob", 50);     // Mid-level bureaucrat, can execute mid-level forms
    Bureaucrat charlie("Charlie", 150); // Low-grade bureaucrat, can't sign or execute most forms

    // 2. Create Forms
    std::cout << "\033[32m" << "2. Creating Forms: " << "\033[0m" << std::endl;
    ShrubberyCreationForm shrubForm("home");
    RobotomyRequestForm robotForm("robot");
    PresidentialPardonForm pardonForm("criminal");

    // 3. Attempt to execute forms without signing
    std::cout << "\033[33m" << "3. Attempting to execute unsigned forms: " << "\033[0m" << std::endl;
    try {
        alice.executeForm(shrubForm);  // Should fail
        alice.executeForm(robotForm);  // Should fail
        alice.executeForm(pardonForm); // Should fail
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // 4. Sign the Forms
    std::cout << "\033[34m" << "4. Signing the forms: " << "\033[0m" << std::endl;
    alice.signForm(shrubForm);
    alice.signForm(robotForm);
    alice.signForm(pardonForm);

    // 5. Charlie attempts to execute signed forms (should fail)
    std::cout << "\033[35m" << "5. Charlie attempts to execute (should fail): " << "\033[0m" << std::endl;
    try {
        charlie.executeForm(shrubForm);
        charlie.executeForm(robotForm);
        charlie.executeForm(pardonForm);
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // 6. Alice executes all forms
    std::cout << "\033[36m" << "6. Alice executes all forms: " << "\033[0m" << std::endl;
    try {
        alice.executeForm(shrubForm);  // Should create ASCII trees
        std::cout << std::endl;
        alice.executeForm(robotForm);  // May succeed or fail
        std::cout << std::endl;
        alice.executeForm(pardonForm); // Should grant a presidential pardon
        std::cout << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
