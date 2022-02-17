/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:06:10 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/09 16:24:38 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	bx, by, cx, cy, px, py;
	Fixed	m, l;
	bx = b.getX() - a.getX();
	by = b.getY() - a.getY();
	cx = c.getX() - a.getX();
	cy = c.getY() - a.getY();
	px = point.getX() - a.getX();
	py = point.getY() - a.getY();
	m = (px * by - bx * py) / (cx * by - bx * cy);
	if (m >= 0 && m <= 1)
	{
		l = (px - m * cx) / bx;
		if (l >= 0 && (m + l) <= 1)
			return (true);
	}
	return (false);
}