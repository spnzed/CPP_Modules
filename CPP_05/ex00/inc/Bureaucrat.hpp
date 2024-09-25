/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:39:47 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/25 11:39:54 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
	private:
		const std::string	name
		int					grade
	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat &a);
		~Bureaucrat(void);
		Bureaucrat &operator=(const Bureaucrat &a);
		std::ostream& operator<<(std::ostream& os, const Bureaucrat& a)

		const std::string	getName(void);
		int					getGrade(void);
		void				incGrade(void);
		void				decGrade(void);
}

#endif
