/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:10:40 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/27 19:50:46 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRESIDENTIAL_HPP
#define PRESIDENTIAL_HPP

#pragma once

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"

#include <iostream>
#include <string>

class Bureaucrat;

class PresidentialPardonForm : public AForm {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;
		const int			_execution_grade;
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm &a);
		~PresidentialPardonForm(void);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &a);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char * what() const throw() {
					return "Grade is too high";
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char * what() const throw() {
					return "Grade is too low";
				}
		};

		const std::string	getName(void) const;
		bool				isSigned(void);
		int					getSignGrade(void) const;
		int					getExecutionGrade(void) const;

		void				incGrade(void);
		void				decGrade(void);

		void				compSignGrade(int grade);
		void				compExecutionGrade(int grade);

		void				beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& a);

#endif
