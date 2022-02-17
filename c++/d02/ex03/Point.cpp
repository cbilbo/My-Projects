/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:53:52 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/09 15:59:15 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"
#include <ostream>

Point::Point() : _x(0), _y(0)
{}

Point::Point(float x, float y) : _x(Fixed(x)), _y(Fixed(y))
{}

Point::Point(Point const &copy) : _x(copy.getX()), _y(copy.getY())
{}

Point::~Point()
{}

Fixed	Point::getX(void) const
{
	return (_x);
}

Fixed	Point::getY(void) const
{
	return (_y);
}

Point	&Point::operator = (Point point)
{
	if (this == &point)
		return (*this);
	const_cast<Fixed&>(_x) = point.getX();
	const_cast<Fixed&>(_y) = point.getY();
	return (*this);
}

std::ostream	&operator<<(std::ostream& os, Point const &point)
{
	os << "x = " << point.getX() << " y = " << point.getY();
	return (os);
}