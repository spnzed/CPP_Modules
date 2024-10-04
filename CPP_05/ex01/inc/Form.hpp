/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:39:47 by aaespino          #+#    #+#             */
/*   Updated: 2024/10/04 14:35:06 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#pragma once

#include "../inc/Bureaucrat.hpp"

#include <iostream>
#include <string>

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;
		const int			_execution_grade;
	public:
		Form(void);
		Form(std::string name, int sign_grade, int execution_grade);
		Form(const Form &a);
		~Form(void);
		Form &operator=(const Form &a);

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

		void				compSignGrade(int grade);
		void				compExecutionGrade(int grade);

		void				beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& a);

#endif
