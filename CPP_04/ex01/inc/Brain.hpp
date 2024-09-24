/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/20 13:08:23 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

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
