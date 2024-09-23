/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/23 12:51:14 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BRAIN_HPP
#define _BRAIN_HPP

#include <string>

#pragma once

class Brain {
    private:
        std::string  ideas[100];
    public:
        Brain(void);
        Brain (const Brain &a);
        ~Brain(void);

        Brain &operator=(const Brain &a); 
};

#endif
