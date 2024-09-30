/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:43:57 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/30 18:05:23 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#pragma once

#include "../inc/AForm.hpp"

class Intern {
	public:
		Intern(void);
		Intern(const Intern &a);
		~Intern(void);
		Intern &operator=(const Intern &a);

        int getForm(std::string form) const;
        AForm*   makeForm(std::string form, std::string target) const;
};

#endif
