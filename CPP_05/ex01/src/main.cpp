/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:37:32 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/27 18:40:19 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"
#include <iostream>

int main() {
    // 1. Create and sign a form
    std::cout << "\033[34m" << "1. Creating a form and signing it: " << "\033[0m" << std::endl;
    Bureaucrat b1("Alice", 2);
    Form form1("Form1", 20, 30);
    std::cout << form1 << std::endl;
    b1.signForm(form1);  // Alice should be able to sign

    // 2. Attempt to sign a form that requires a higher signing grade
    std::cout << "\033[33m" << "2. Trying to have Bob sign the form: " << "\033[0m" << std::endl;
    Bureaucrat b2("Bob", 50);
    b2.signForm(form1);  // Bob should not be able to sign

    // 3. Create another bureaucrat with a higher grade who should be able to sign
    std::cout << "\033[34m" << "3. Creating a bureaucrat with a higher grade: " << "\033[0m" << std::endl;
    Bureaucrat b3("David", 15);
    std::cout << b3 << std::endl;
    b3.signForm(form1);  // David should be able to sign

    // 4. Create a form with a high signing grade and try to sign it
    std::cout << "\033[33m" << "4. Creating a form with a high signing grade: " << "\033[0m" << std::endl;
    Form form2("Form2", 1, 30);  // Very high signing grade
    std::cout << form2 << std::endl;

    // 5. Attempt to sign with a bureaucrat with a lower grade
    std::cout << "\033[34m" << "5. Trying to have Alice sign Form2: " << "\033[0m" << std::endl;
    b1.signForm(form2);  // Alice should not be able to sign

    // 6. Attempt to sign the high grade form with a bureaucrat who can sign
    std::cout << "\033[33m" << "6. Trying to have David sign Form2: " << "\033[0m" << std::endl;
    b3.signForm(form2);  // David should be able to sign

    // 7. Attempt to sign an already signed form
    std::cout << "\033[34m" << "7. Attempting to sign an already signed form: " << "\033[0m" << std::endl;
    b3.signForm(form1);  // David should not be able to sign it again

    // 8. Check signing of multiple forms
    std::cout << "\033[33m" << "8. Creating and signing multiple forms: " << "\033[0m" << std::endl;
    Form form3("Form3", 10, 10);
    Form form4("Form4", 50, 50);
    std::cout << form3 << std::endl;
    std::cout << form4 << std::endl;

    // David should be able to sign both forms
    b3.signForm(form3);
    b3.signForm(form4);

    return 0;
}
