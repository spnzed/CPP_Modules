/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:13:53 by aaespino          #+#    #+#             */
/*   Updated: 2024/11/26 17:07:02 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_HPP
#define BITCOIN_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <map>

class Bitcoin {
    public:
        Bitcoin(void);
        ~Bitcoin(void);
        Bitcoin(const Bitcoin & a);
        Bitcoin &operator=(const Bitcoin & a);
        
        void makeInput(std::string f);
        void printOutput(std::multimap<std::string, float> *data);

    private:
        std::multimap <std::string, float> _logs;

        //  Validacion
        int isDigits(std::string& str);
        int countDelimiter(std::string date, char delimiter);
        int compDate(std::string date);
        int compValue(float num);
        //  General
        std::string trim(const std::string& str);
        float exchangeRate(std::multimap<std::string, float> *data, const std::string& key, float mul);
};

#endif
