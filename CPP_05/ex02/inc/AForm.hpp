/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:39:47 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/27 20:04:45 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#pragma once

#include "../inc/Bureaucrat.hpp"

#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;
		const int			_execution_grade;
	public:
		AForm(void);
		AForm(std::string name, int sign_grade, int execution_grade);
		AForm(const AForm &a);
		~AForm(void);
		AForm &operator=(const AForm &a);

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
		void				execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& a);

#endif
