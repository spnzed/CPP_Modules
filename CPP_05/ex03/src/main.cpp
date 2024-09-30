/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:37:32 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/30 18:25:47 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"
#include <iostream>

int main() {
    // 1. Create Bureaucrats
    std::cout << "\033[31m" << "1. Creating Bureaucrats: " << "\033[0m" << std::endl;
    Bureaucrat alice("Alice", 1);  // High-grade bureaucrat, can sign and execute everything
    Bureaucrat bob("Bob", 5);      // Mid-level bureaucrat, can execute mid-level forms
    Bureaucrat charlie("Charlie", 150); // Low-grade bureaucrat, can't sign or execute most forms
    std::cout << std::endl;

    // 2. Create Intern
    std::cout << "\033[32m" << "2. Creating Intern: " << "\033[0m" << std::endl;
    Intern someRandomIntern;
    std::cout << std::endl;

    // 3. Create Forms via Intern
    std::cout << "\033[33m" << "3. Creating Forms via Intern: " << "\033[0m" << std::endl;
    AForm* shrubForm = someRandomIntern.makeForm("shrubbery creation", "home");
    AForm* robotForm = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm* pardonForm = someRandomIntern.makeForm("presidential pardon", "criminal");
    std::cout << std::endl;

    // 4. Attempt to create an invalid form
    std::cout << "\033[34m" << "4. Attempting to create an invalid form: " << "\033[0m" << std::endl;
    AForm* formInvalid = someRandomIntern.makeForm("invalid form", "Nowhere");
    std::cout << std::endl;

    // 5. Attempt to execute forms without signing
    std::cout << "\033[35m" << "5. Attempting to execute unsigned forms: " << "\033[0m" << std::endl;
    try {
        alice.executeForm(*shrubForm);  // Should succeed
        bob.executeForm(*robotForm);     // Should fail
        charlie.executeForm(*pardonForm); // Should fail
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // 6. Sign the Forms
    std::cout << "\033[36m" << "6. Signing the forms: " << "\033[0m" << std::endl;
    alice.signForm(*shrubForm);
    alice.signForm(*robotForm);
    alice.signForm(*pardonForm);
    std::cout << std::endl;

    // 7. Charlie attempts to execute signed forms (should fail)
    std::cout << "\033[31m" << "7. Charlie attempts to execute signed forms (should fail): " << "\033[0m" << std::endl;
    try {
        charlie.executeForm(*shrubForm);
        charlie.executeForm(*robotForm);
        charlie.executeForm(*pardonForm);
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // 8. Bob executes signed forms
    std::cout << "\033[32m" << "8. Bob executes signed forms: " << "\033[0m" << std::endl;
    try {
        std::cout << std::endl;
        bob.executeForm(*shrubForm);  // Should create ASCII trees
        std::cout << std::endl;
        bob.executeForm(*robotForm);  // May succeed or fail
        std::cout << std::endl;
        bob.executeForm(*pardonForm); // Should grant a presidential pardon
        std::cout << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // 9. Clean up
    delete shrubForm;        // Liberar memoria si el formulario fue creado
    delete robotForm;       // Liberar memoria si el formulario fue creado
    delete pardonForm;      // Liberar memoria si el formulario fue creado
    delete formInvalid;      // Liberar memoria si el formulario fue creado
    std::cout << std::endl;

    return 0;
}
