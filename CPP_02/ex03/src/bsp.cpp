/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:25:08 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/17 19:44:08 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

bool bsp( Point const a,  Point const b, Point const c, Point const point) {

    float area_abc = ((b.getX().toFloat() - a.getX().toFloat())*(c.getY().toFloat() - a.getY().toFloat()) -
                    (c.getX().toFloat() - a.getX().toFloat())*(b.getY().toFloat() - a.getY().toFloat())) / 2.0;
    
    float area_pbc = ((b.getX().toFloat() - point.getX().toFloat())*(c.getY().toFloat() - point.getY().toFloat()) -
                    (c.getX().toFloat() - point.getX().toFloat())*(b.getY().toFloat() - point.getY().toFloat())) / 2.0;
    float area_pab = ((a.getX().toFloat() - point.getX().toFloat())*(b.getY().toFloat() - point.getY().toFloat()) -
                    (b.getX().toFloat() - point.getX().toFloat())*(a.getY().toFloat() - point.getY().toFloat())) / 2.0;
    float area_pca = ((c.getX().toFloat() - point.getX().toFloat())*(a.getY().toFloat() - point.getY().toFloat()) -
                    (a.getX().toFloat() - point.getX().toFloat())*(c.getY().toFloat() - point.getY().toFloat())) / 2.0;

    if (area_abc < 0)
        area_abc *= -1;
    if (area_pbc < 0)
        area_pbc *= -1;
    if (area_pab < 0)
        area_pab *= -1;
    if (area_pca < 0)
        area_pca *= -1;

    if (area_abc == area_pab + area_pbc + area_pca)
        return true;

    return false;
}
