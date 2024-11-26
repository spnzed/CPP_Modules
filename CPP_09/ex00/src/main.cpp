/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:19:28 by aaespino          #+#    #+#             */
/*   Updated: 2024/11/26 17:05:33 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

std::multimap<std::string, float> makeData(void) {
    std::ifstream is("data.csv");

    std::multimap<std::string, float> ret;

    if (!is) { 
        std::cout << "Error, could not open file." << std::endl; 
        return ret;
    }

    std::string line;
    std::string row;
    std::string val_s;
    float val;
    
    while(std::getline(is, line)) {
        std::stringstream ss(line);
        std::getline (ss, row , ',');
        std::getline (ss, val_s);

        char *end;
        val = std::strtof(val_s.c_str(), &end);
        ret.insert(std::make_pair(row, val));
    }
    is.close();

    return ret;
}

int main (int argc, char **argv) {

    Bitcoin btc;

    if (argc != 2) {
        std::cout << "Error: could not open file." << std::endl;
    } else {
        std::multimap<std::string, float> data = makeData();
        btc.makeInput(argv[1]);
        btc.printOutput(&data);
    }
    return 0;
}
