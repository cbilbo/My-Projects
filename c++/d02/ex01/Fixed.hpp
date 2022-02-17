/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:32:14 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/08 19:21:49 by cbilbo           ###   ########.fr       */
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
	Fixed& operator=(Fixed const &fix);
	~Fixed();
	float toFloat(void) const;
	int toInt(void) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream& os, Fixed const &object);