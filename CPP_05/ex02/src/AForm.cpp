/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:12:34 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/27 20:12:48 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

AForm::AForm(void) : _name("Default_Burocrat"), _signed(false), _sign_grade(1), _execution_grade(1) {
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, int sign_grade, int execution_grade) : _name(name), _signed(false), _sign_grade(sign_grade) , _execution_grade(execution_grade) {
    std::cout << "AForm constructor called" << std::endl;
    compSignGrade(sign_grade);
    compExecutionGrade(execution_grade);
}

AForm::AForm(const AForm &a) : _name(a._name), _signed(a.isSigned()), _sign_grade(a._sign_grade) , _execution_grade(a._execution_grade) {
    std::cout << "AForm copy constructor called" << std::endl;
    *this = a;
}

AForm::~AForm(void) {
    std::cout << "AForm destructor called" << std::endl;   
}

AForm& AForm::operator=(const AForm &a) {
    std::cout << "AForm assginment operator called" << std::endl;
    if (this != &a) {
        this->_signed = a._signed;
    }
    return *this;
}

const std::string   AForm::getName(void) const {
    return this->_name;
}

bool    AForm::isSigned(void) {
    return this->_signed;
}

int AForm::getSignGrade(void) const {
    return this->_sign_grade;
}

int AForm::getExecutionGrade(void) const {
    return this->_execution_grade;
}

void    AForm::compSignGrade(int grade) {
    try {   
        if (grade > 150) {
            throw AForm::GradeTooLowException();
        }
        else if (grade < 1) {
            throw AForm::GradeTooHighException();
        }
    }
    catch (const std::exception& errorMessage) {
        std::cerr << "Error: " << errorMessage.what() << std::endl;
    }
}

void    AForm::compExecutionGrade(int grade) {
    try {   
        if (grade > 150) {
            throw AForm::GradeTooLowException();
        }
        else if (grade < 1) {
            throw AForm::GradeTooHighException();
        }
    }
    catch (const std::exception& errorMessage) {
        std::cerr << "Error: " << errorMessage.what() << std::endl;
    }
}

void    AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > this->_sign_grade)
        throw AForm::GradeTooLowException();
    else
        this->_signed = true;
}

void    AForm::execute(Bureaucrat const & executor) const {
    if (this->_signed) {
        if (executor.getGrade() > this->_execution_grade)
            throw AForm::GradeTooLowException;
        else {
            //execute
            std::cout << executor.getName() << " executed AForm" << std::endl;
        }
    }
    else
        std::cout << executor.getName() << " couldn't execute AForm, it's not signed." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const AForm& a) {
    os << a.getName() << ", AForm sign grade " << a.getSignGrade() << ", AForm execution grade " << a.getExecutionGrade() ;
    return os;
}
