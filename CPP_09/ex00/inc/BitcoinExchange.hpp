/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:13:53 by aaespino          #+#    #+#             */
/*   Updated: 2024/10/15 16:14:15 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_HPP
#define BITCOIN_HPP

#include <iostream>
#include <string>
#include <map>

class Bitcoin {
    private:
    public:
        std::multimap <std::string, float> _logs;
        Bitcoin(void);
        ~Bitcoin(void);
        Bitcoin(const Bitcoin & a);
        Bitcoin &operator=(const Bitcoin & a);
};

#endif
