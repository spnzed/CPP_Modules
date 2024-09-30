/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:51:48 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/30 17:11:23 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/Bureaucrat.hpp"

#include <string>
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 25, 5), _target(target) {
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &a) : AForm("ShrubberyCreationForm", 25, 5) {
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
    *this = a;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;   
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &a) {
    std::cout << "ShrubberyCreationForm assginment operator called" << std::endl;
    if (this != &a) {
        this->_signed = a.isSigned();
        this->_target = a._target;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& a) {
    os << a.getName() << ", ShrubberyCreationForm sign grade " << a.getSignGrade() << ", ShrubberyCreationForm execution grade " << a.getExecutionGrade() ;
    return os;
}

void    ShrubberyCreationForm::action(void) const {

    std::string filename = this->_target.c_str();

    std::ofstream new_file((filename + "_shrubbery").c_str());
    if (!new_file.is_open()) {
        std::cerr << "Error: Cannot open output file for modification." << std::endl;
        return ;
    }

    new_file << "       _-_                 _-_          " << std::endl;
    new_file << "    /~~   ~~\\           /~~   ~~\\      " << std::endl;
    new_file << " /~~         ~~\\     /~~         ~~\\   " << std::endl;
    new_file << "{               }   {               }  " << std::endl;
    new_file << " \\  _-     -_  /     \\  _-     -_  /   " << std::endl;
    new_file << "   ~  \\\\ //  ~         ~  \\\\ //  ~      " << std::endl;
    new_file << "_- -   | | _- _      _- -  | | _- _   " << std::endl;
    new_file << "  _ -  | |   -_       _ -  | |   -_    " << std::endl;
    new_file << "      // \\\\               // \\\\         " << std::endl;

    new_file.close();

    return ;
}
