/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:10:40 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/27 19:59:40 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ROBOTOMY_HPP
#define ROBOTOMY_HPP

#pragma once

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"

#include <iostream>
#include <string>

class Bureaucrat;

class RobotomyRequestForm : public AForm {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;
		const int			_execution_grade;
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm &a);
		~RobotomyRequestForm(void);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &a);

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
		void				execute(Bureaucrat const & executor);
};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& a);

#endif
