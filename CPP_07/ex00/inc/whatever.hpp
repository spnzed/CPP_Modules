/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:44:00 by aaespino          #+#    #+#             */
/*   Updated: 2024/10/02 17:07:22 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
T max(T x, T y)
{
    return (x > y) ? x : y;
}

template <typename T>
T min(T x, T y)
{
    return (x < y) ? x : y;
}

template <typename T>
void swap(T& x, T& y)
{
    T tmp;

    tmp = x;
    x = y;
    y = tmp;
}

#endif
