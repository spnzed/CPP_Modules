/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:52:02 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/27 19:52:04 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : _name("robotomy"), _signed(false), _sign_grade(145), _execution_grade(137) {
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string name, int sign_grade, int execution_grade) : _name(name), _signed(false), _sign_grade(sign_grade) , _execution_grade(execution_grade) {
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
    compSignGrade(sign_grade);
    compExecutionGrade(execution_grade);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &a) : _name(a._name), _signed(a.isSigned()), _sign_grade(a._sign_grade) , _execution_grade(a._execution_grade) {
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
    *this = a;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
    std::cout << "RobotomyRequestForm destructor called" << std::endl;   
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &a) {
    std::cout << "RobotomyRequestForm assginment operator called" << std::endl;
    if (this != &a) {
        this->_signed = a._signed;
    }
    return *this;
}

const std::string   RobotomyRequestForm::getName(void) const {
    return this->_name;
}

bool    RobotomyRequestForm::isSigned(void) {
    return this->_signed;
}

int RobotomyRequestForm::getSignGrade(void) const {
    return this->_sign_grade;
}

int RobotomyRequestForm::getExecutionGrade(void) const {
    return this->_execution_grade;
}

void    RobotomyRequestForm::compSignGrade(int grade) {
    try {   
        if (grade > 150) {
            throw RobotomyRequestForm::GradeTooLowException();
        }
        else if (grade < 1) {
            throw RobotomyRequestForm::GradeTooHighException();
        }
    }
    catch (const std::exception& errorMessage) {
        std::cerr << "Error: " << errorMessage.what() << std::endl;
    }
}

void    RobotomyRequestForm::compExecutionGrade(int grade) {
    try {   
        if (grade > 150) {
            throw RobotomyRequestForm::GradeTooLowException();
        }
        else if (grade < 1) {
            throw RobotomyRequestForm::GradeTooHighException();
        }
    }
    catch (const std::exception& errorMessage) {
        std::cerr << "Error: " << errorMessage.what() << std::endl;
    }
}

void    RobotomyRequestForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > this->_sign_grade)
        throw RobotomyRequestForm::GradeTooLowException();
    else
        this->_signed = true;
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& a) {
    os << a.getName() << ", RobotomyRequestForm sign grade " << a.getSignGrade() << ", RobotomyRequestForm execution grade " << a.getExecutionGrade() ;
    return os;
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (this->_signed) {
        if (executor.getGrade() > this->_execution_grade)
            throw RobotomyRequestForm::GradeTooLowException;
        else {
            //execute
            std::cout << executor.getName() << " executed RobotomyRequestForm" << std::endl;
        }
    }
    else
        std::cout << executor.getName() << " couldn't execute RobotomyRequestForm, it's not signed." << std::endl;
}
