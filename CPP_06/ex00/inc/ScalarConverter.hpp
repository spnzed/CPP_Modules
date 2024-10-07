/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:50:43 by aaespino          #+#    #+#             */
/*   Updated: 2024/10/07 13:32:26 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#pragma once

#include <iostream>
#include <string>

class ScalarConverter {
    public:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter& a);
        ~ScalarConverter(void);
        ScalarConverter &operator=(const ScalarConverter& a);
        
        static void convert(std::string);
};

#endif
