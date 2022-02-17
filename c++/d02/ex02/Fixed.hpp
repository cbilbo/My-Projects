/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:32:14 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/10 17:19:05 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <ostream>

class Fixed
{
private:
	int _fpv;
	static int const _bits = 8;
public:
	Fixed();
	Fixed(int const par);
	Fixed(float const par);
	Fixed(Fixed const& copy);
	~Fixed();

	Fixed	&operator = (Fixed const &fix);
	Fixed	operator + (Fixed const &fix);
	Fixed	operator - (Fixed const &fix);
	Fixed	operator * (Fixed const &fix);
	Fixed	operator / (Fixed const &fix);
	bool	operator <(Fixed const &fix) const;
	bool	operator >(Fixed const &fix) const;
	bool	operator <=(Fixed const &fix) const;
	bool	operator >=(Fixed const &fix) const;
	bool	operator !=(Fixed const &fix) const;
	bool	operator == (Fixed const &fix) const;
	Fixed	&operator ++ ();
	Fixed	&operator -- ();
	Fixed	operator ++ (int);
	Fixed	operator -- (int);
	static Fixed	&min(Fixed &fix1, Fixed &fix2);
	static Fixed const	&min(Fixed const &fix1, Fixed const &fix2);
	static Fixed	&max(Fixed &fix1, Fixed &fix2);
	static Fixed const	&max(Fixed const &fix1, Fixed const &fix2);
	float	toFloat(void) const;
	int	toInt(void) const;
	int	getRawBits(void) const;
	void	setRawBits(int const raw);
};

std::ostream	&operator<<(std::ostream &os, Fixed const &fix);