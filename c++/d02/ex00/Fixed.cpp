/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:32:05 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/24 20:42:22 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _fpv(0)
{
	std::cout << "Default constructor called" << std::endl;
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

Fixed::Fixed(Fixed const& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	_fpv = copy.getRawBits();
}

Fixed& Fixed::operator=(Fixed &fix)
{
	std::cout << "Assignation operator called" << std::endl;
	_fpv = fix.getRawBits();
	return (*this);
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}