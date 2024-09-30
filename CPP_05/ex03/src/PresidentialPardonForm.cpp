/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:11:00 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/30 17:14:13 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 145, 137), _target(target) {
    std::cout << "PresidentialPardonForm constructor called" << std::endl;;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &a) : AForm("PresidentialPardonForm", 145, 137) {
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
    *this = a;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
    std::cout << "PresidentialPardonForm destructor called" << std::endl;   
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &a) {
    std::cout << "PresidentialPardonForm assginment operator called" << std::endl;
    if (this != &a) {
        this->_signed = a.isSigned();
        this->_target = a._target;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& a) {
    os << a.getName() << ", PresidentialPardonForm sign grade " << a.getSignGrade() << ", PresidentialPardonForm execution grade " << a.getExecutionGrade() ;
    return os;
}

void    PresidentialPardonForm::action(void) const {
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
