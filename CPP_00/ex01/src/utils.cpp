/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:58:46 by ffornes-          #+#    #+#             */
/*   Updated: 2024/09/14 14:38:56 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.hpp"

std::string add_s(int n) {
	std::string ret;

	while (n)
	{
		ret.append(" ");
		n--;
	}
	return (ret);
}

std::string fix_w(std::string str) {
	if (str.size() > 10)
	{
		str.resize(10);
		str[str.size() - 1] = '.';
	}
	return (str);
}
