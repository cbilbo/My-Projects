/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:32:05 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/08 19:23:03 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _fpv(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const par)
{
	std::cout << "Int constructor called" << std::endl;
	_fpv = par << _bits;
}

Fixed::Fixed(float const par)
{
	std::cout << "Float constructor called" << std::endl;
	_fpv = (int)(roundf(par * (1 << _bits)));
}

Fixed::Fixed(Fixed const& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	_fpv = copy.getRawBits();
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fpv);
}

void	Fixed::setRawBits(int const raw)
{
	_fpv = raw;
	std::cout << "getRawBits member function called" << std::endl;
}

int	Fixed::toInt(void) const
{
	return ((int)(_fpv >> _bits));
}

float Fixed::toFloat(void) const
{
	return ((float)_fpv / (float)(1 << _bits));
}

Fixed& Fixed::operator=(Fixed const &fix)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this == &fix)
		return (*this);
	_fpv = fix.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream& os, Fixed const &fix)
{
	os << fix.toFloat();
	return (os);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}