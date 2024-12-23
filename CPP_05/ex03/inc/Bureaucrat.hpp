/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:39:47 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/30 16:10:40 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#pragma once

#include "../inc/AForm.hpp"

#include <iostream>
#include <string>

class AForm;

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &a);
		~Bureaucrat(void);
		Bureaucrat &operator=(const Bureaucrat &a);

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
		int					getGrade(void) const;

		void				incGrade(void);
		void				decGrade(void);

		void				setGrade(int grade);
		void				signForm(AForm & f) const;
		void				executeForm(AForm const & form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& a);

#endif
