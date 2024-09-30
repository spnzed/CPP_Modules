/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:10:40 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/30 16:58:47 by aaespino         ###   ########.fr       */
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
		std::string	_target;
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &a);
		~RobotomyRequestForm(void);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &a);

		void				action(void) const ;
};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& a);

#endif
