/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:55:23 by aaespino          #+#    #+#             */
/*   Updated: 2024/10/15 16:14:25 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

Bitcoin::Bitcoin(void) {
}

Bitcoin::~Bitcoin(void) {
}

Bitcoin::Bitcoin(const Bitcoin & a) {
    *this = a;
}

Bitcoin& Bitcoin::operator=(const Bitcoin & a) {
    _logs = a._logs;
    return *this;
}
