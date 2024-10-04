/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:31:16 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/27 16:33:52 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

Form::Form(void) : _name("Default_Burocrat"), _signed(false), _sign_grade(1), _execution_grade(1) {
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int sign_grade, int execution_grade) : _name(name), _signed(false), _sign_grade(sign_grade) , _execution_grade(execution_grade) {
    std::cout << "Form constructor called" << std::endl;
    compSignGrade(sign_grade);
    compExecutionGrade(execution_grade);
}

Form::Form(const Form &a) : _name(a._name), _signed(a._signed), _sign_grade(a._sign_grade) , _execution_grade(a._execution_grade) {
    std::cout << "Form copy constructor called" << std::endl;
    *this = a;
}

Form::~Form(void) {
    std::cout << "Form destructor called" << std::endl;   
}

Form& Form::operator=(const Form &a) {
    std::cout << "Form assginment operator called" << std::endl;
    if (this != &a) {
        this->_signed = a._signed;
    }
    return *this;
}

const std::string   Form::getName(void) const {
    return this->_name;
}

bool    Form::isSigned(void) {
    return this->_signed;
}

int Form::getSignGrade(void) const {
    return this->_sign_grade;
}

int Form::getExecutionGrade(void) const {
    return this->_execution_grade;
}

void    Form::compSignGrade(int grade) {
    try {   
        if (grade > 150) {
            throw Form::GradeTooLowException();
        }
        else if (grade < 1) {
            throw Form::GradeTooHighException();
        }
    }
    catch (const std::exception& errorMessage) {
        std::cerr << "Error: " << errorMessage.what() << std::endl;
    }
}

void    Form::compExecutionGrade(int grade) {
    try {   
        if (grade > 150) {
            throw Form::GradeTooLowException();
        }
        else if (grade < 1) {
            throw Form::GradeTooHighException();
        }
    }
    catch (const std::exception& errorMessage) {
        std::cerr << "Error: " << errorMessage.what() << std::endl;
    }
}

void    Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= this->_sign_grade)
        this->_signed = true;
    else
        throw Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& a) {
    os << a.getName() << ", Form sign grade " << a.getSignGrade() << ", Form execution grade " << a.getExecutionGrade() ;
    return os;
}
