/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:11:00 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/27 20:11:08 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : _name("robotomy"), _signed(false), _sign_grade(145), _execution_grade(137) {
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name, int sign_grade, int execution_grade) : _name(name), _signed(false), _sign_grade(sign_grade) , _execution_grade(execution_grade) {
    std::cout << "PresidentialPardonForm constructor called" << std::endl;
    compSignGrade(sign_grade);
    compExecutionGrade(execution_grade);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &a) : _name(a._name), _signed(a.isSigned()), _sign_grade(a._sign_grade) , _execution_grade(a._execution_grade) {
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
    *this = a;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
    std::cout << "PresidentialPardonForm destructor called" << std::endl;   
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &a) {
    std::cout << "PresidentialPardonForm assginment operator called" << std::endl;
    if (this != &a) {
        this->_signed = a._signed;
    }
    return *this;
}

const std::string   PresidentialPardonForm::getName(void) const {
    return this->_name;
}

bool    PresidentialPardonForm::isSigned(void) {
    return this->_signed;
}

int PresidentialPardonForm::getSignGrade(void) const {
    return this->_sign_grade;
}

int PresidentialPardonForm::getExecutionGrade(void) const {
    return this->_execution_grade;
}

void    PresidentialPardonForm::compSignGrade(int grade) {
    try {   
        if (grade > 150) {
            throw PresidentialPardonForm::GradeTooLowException();
        }
        else if (grade < 1) {
            throw PresidentialPardonForm::GradeTooHighException();
        }
    }
    catch (const std::exception& errorMessage) {
        std::cerr << "Error: " << errorMessage.what() << std::endl;
    }
}

void    PresidentialPardonForm::compExecutionGrade(int grade) {
    try {   
        if (grade > 150) {
            throw PresidentialPardonForm::GradeTooLowException();
        }
        else if (grade < 1) {
            throw PresidentialPardonForm::GradeTooHighException();
        }
    }
    catch (const std::exception& errorMessage) {
        std::cerr << "Error: " << errorMessage.what() << std::endl;
    }
}

void    PresidentialPardonForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > this->_sign_grade)
        throw PresidentialPardonForm::GradeTooLowException();
    else
        this->_signed = true;
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& a) {
    os << a.getName() << ", PresidentialPardonForm sign grade " << a.getSignGrade() << ", PresidentialPardonForm execution grade " << a.getExecutionGrade() ;
    return os;
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (this->_signed) {
        if (executor.getGrade() > this->_execution_grade)
            throw PresidentialPardonForm::GradeTooLowException;
        else {
            //execute
            std::cout << executor.getName() << " executed PresidentialPardonForm" << std::endl;
        }
    }
    else
        std::cout << executor.getName() << " couldn't execute PresidentialPardonForm, it's not signed." << std::endl;
}
