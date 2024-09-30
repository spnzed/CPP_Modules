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

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unistd.h>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::cout << "RobotomyRequestForm constructor called" << std::endl;;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &a) :  AForm("RobotomyRequestForm", 72, 45) {
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
    *this = a;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
    std::cout << "RobotomyRequestForm destructor called" << std::endl;   
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &a) {
    std::cout << "RobotomyRequestForm assginment operator called" << std::endl;
    if (this != &a) {
        this->_signed = a.isSigned();
        this->_target = a._target;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& a) {
    os << a.getName() << ", RobotomyRequestForm sign grade " << a.getSignGrade() << ", RobotomyRequestForm execution grade " << a.getExecutionGrade() ;
    return os;
}

void    RobotomyRequestForm::action(void) const {
    static int rand;

    std::srand(std::time(NULL));
    rand += std::rand() % 10;
    std::cout << "Initiating robotomy procedure on " << this->_target << "..." << std::endl;
    if (rand % 2)
        std::cout << "Brrr... brrr... 🛠 Drilling noises... " << this->_target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Brrr... brrr... 🛠 Drilling noises... The robotomy of " << this->_target << " has failed." << std::endl;
}
