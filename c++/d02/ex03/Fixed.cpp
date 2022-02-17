/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:32:05 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/08 22:50:58 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _fpv(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const par)
{
	//std::cout << "Int constructor called" << std::endl;
	_fpv = par << _bits;
}

Fixed::Fixed(float const par)
{
	//std::cout << "Float constructor called" << std::endl;
	_fpv = (int)(roundf(par * (1 << _bits)));
}

Fixed::Fixed(Fixed const& copy)
{
	//std::cout << "Copy constructor called" << std::endl;
	_fpv = copy.getRawBits();
}

int	Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (_fpv);
}

void	Fixed::setRawBits(int const raw)
{
	//std::cout << "getRawBits member function called" << std::endl;
	_fpv = raw;
}

int	Fixed::toInt(void) const
{
	//std::cout << "toInt member function called" << std::endl;
	return ((int)(_fpv >> _bits));
}

float	Fixed::toFloat(void) const
{
	//std::cout << "toFloat member function called" << std::endl;
	return ((float)_fpv / (float)(1 << _bits));
}

Fixed	&Fixed::operator = (Fixed const &fix)
{
	//std::cout << "Assignation operator called" << std::endl;
	if (this == &fix)
		return (*this);
	_fpv = fix.getRawBits();
	return (*this);
}

Fixed	Fixed::operator + (Fixed const &fix)
{
	//std::cout << "+ operator called" << std::endl;
	Fixed	res;
	
	res.setRawBits(getRawBits() + fix.getRawBits());
	return (res);
}

Fixed	Fixed::operator - (Fixed const &fix)
{
	//std::cout << "- operator called" << std::endl;
	Fixed res;
	
	res.setRawBits(getRawBits() - fix.getRawBits());
	return (res);
}

Fixed Fixed::operator * (Fixed const &fix)
{
	//std::cout << "* operator called" << std::endl;
	Fixed res;
	
	res.setRawBits((getRawBits() * fix.getRawBits()) >> _bits);
	return (res);
}

Fixed Fixed::operator / (Fixed const &fix)
{
	//std::cout << "/ operator called" << std::endl;
	Fixed res;

	res.setRawBits((getRawBits() << _bits) / fix.getRawBits());
	return (res);
}

bool operator <(Fixed const &fix1, Fixed const &fix2)
{
	//std::cout << "< operator called" << std::endl;
	return (fix1.getRawBits() < fix2.getRawBits());
}

bool operator >(Fixed const &fix1, Fixed const &fix2)
{
	//std::cout << "> operator called" << std::endl;
	return (fix1.getRawBits() > fix2.getRawBits());
}

bool operator <=(Fixed const &fix1, Fixed const &fix2)
{
	//std::cout << "<= operator called" << std::endl;
	return (fix1.getRawBits() <= fix2.getRawBits());
}

bool operator >=(Fixed const &fix1, Fixed const &fix2)
{
	//std::cout << ">= operator called" << std::endl;
	return (fix1.getRawBits() >= fix2.getRawBits());
}

bool operator !=(Fixed const &fix1, Fixed const &fix2)
{
	//std::cout << "!= operator called" << std::endl;
	return (fix1.getRawBits() != fix2.getRawBits());
}

bool operator ==(Fixed const &fix1, Fixed const &fix2)
{
	//std::cout << "== operator called" << std::endl;
	return (fix1.getRawBits() == fix2.getRawBits());
}

std::ostream	&operator<<(std::ostream& os, Fixed const &fix)
{
	//std::cout << "<< operator called" << std::endl;
	os << fix.toFloat();
	return (os);
}

Fixed	&Fixed::operator++()
{
	//std::cout << "Prefix increment operator called" << std::endl;
	++_fpv;
	return (*this);
}

Fixed	&Fixed::operator --()
{
	//std::cout << "Prefix decrement operator called" << std::endl;
	--_fpv;
	return (*this);
}

Fixed	Fixed::operator ++ (int)
{
	//std::cout << "Postfix increment operator called" << std::endl;
	Fixed res;

	res.setRawBits(_fpv);
	++_fpv;
	return (res);
}

Fixed	Fixed::operator -- (int)
{
	//std::cout << "Postfix decrement operator called" << std::endl;
	Fixed res;
	
	res.setRawBits(_fpv);
	--_fpv;
	return (res);
}

Fixed	&Fixed::min(Fixed &fix1, Fixed &fix2)
{
	if (fix1 <= fix2)
		return (fix1);
	return (fix2);
}

Fixed const	&Fixed::min(Fixed const &fix1, Fixed const &fix2)
{
	if (fix1 <= fix2)
		return (fix1);
	return (fix2);
}

Fixed	&Fixed::max(Fixed &fix1, Fixed &fix2)
{
	if (fix1 > fix2)
		return (fix1);
	return (fix2);
}

Fixed const	&Fixed::max(Fixed const &fix1, Fixed const &fix2)
{
	if (fix1 > fix2)
		return (fix1);
	return (fix2);
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}