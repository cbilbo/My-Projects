/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:54:01 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/09 17:03:18 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Fixed.hpp"
#include <ostream>

class Point
{
private:
	Fixed const _x;
	Fixed const _y;
public:
	Point();
	Point(float x, float y);
	Point(Point const &copy);
	~Point();

	Fixed	getX(void) const;
	Fixed	getY(void) const;
	Point &operator = (Point const point);
};

std::ostream	&operator<<(std::ostream &os, Point const &point);
bool			bsp( Point const a, Point const b, Point const c, Point const point);
