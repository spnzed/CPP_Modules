/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:31:13 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/25 11:36:48 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

Bureaucrat::Bureaucrat(void) {
    
}

Bureaucrat::Bureaucrat(const Bureaucrat &a) {
    
}

Bureaucrat::~Bureaucrat(void) {
    
}

Bureaucrat& Bureaucrat::&operator=(const Bureaucrat &a) {
    
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& a) {
    os << a.getName() << ", bureaucrat grade " << a.getGrade();
    return os;
}

const std::string   Bureaucrat::getName(void) {
    
}

int Bureaucrat::getGrade(void) {
    
}

void    Bureaucrat::incGrade(void) {
    
}

void    Bureaucrat::decGrade(void) {
    
}
