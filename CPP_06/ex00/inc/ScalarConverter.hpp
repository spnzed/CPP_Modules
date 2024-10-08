/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:50:43 by aaespino          #+#    #+#             */
/*   Updated: 2024/10/08 15:41:18 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#pragma once

#include <iostream>
#include <string>

class ScalarConverter {
    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter& a);
        ~ScalarConverter(void);
        ScalarConverter &operator=(const ScalarConverter& a);
    public:
        static void convert(std::string);
};

#endif
