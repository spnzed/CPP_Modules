/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:31:16 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/30 17:14:47 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default_Burocrat"), _grade(150) {
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(0) {
    std::cout << "Bureaucrat " << this->_name << " constructor called" << std::endl;
    setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &a) {
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    *this = a;
}

Bureaucrat::~Bureaucrat(void) {
    std::cout << "Bureaucrat " << this->_name << " destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &a) {
    std::cout << "Bureaucrat assginment operator called" << std::endl;
    if (this != &a) {
        this->_grade = a._grade;
    }
    return *this;
}

const std::string   Bureaucrat::getName(void) const {
    return this->_name;
}

int Bureaucrat::getGrade(void) const {
    return this->_grade;
}

void    Bureaucrat::incGrade(void) {
    setGrade(this->_grade + 1);
}

void    Bureaucrat::decGrade(void) {
    setGrade(this->_grade - 1);
}

void    Bureaucrat::setGrade(int grade) {
    try {   
        if (grade > 150) {
            this->_grade = 150;
            throw Bureaucrat::GradeTooLowException();
        }
        else if (grade < 1) {
            this->_grade = 1;
            throw Bureaucrat::GradeTooHighException();
        }
        this->_grade = grade;
    }
    catch (const std::exception& errorMessage) {
        std::cerr << "Error: " << errorMessage.what() << std::endl;
    } 
}

void    Bureaucrat::signForm(AForm & f) const {
    if (!f.isSigned()) {
        try {
            f.beSigned(*this);
            std::cout << this->_name << " signed " << f.getName() << std::endl;
        } 
        catch (AForm::GradeTooLowException) {
            std::cout << this->_name << " couldn't sign " << f.getName() << ", burocrat's grade is too low." << std::endl;
        }
    }
    else {
        std::cout << this->_name << " couldn't sign " << f.getName() << ", it's already signed." << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) {
	try {
		form.execute(*this);
    }
	catch ( AForm::GradeTooLowException& e ) {
		std::cerr << this->_name << " couldn't execute " << form.getName() << " because " << this->_name << "'s grade is too low" << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& a) {
    os << a.getName() << ", bureaucrat grade " << a.getGrade();
    return os;
}
