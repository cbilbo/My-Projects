/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:32:14 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/24 21:05:05 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Fixed
{
private:
	int _fpv;
	static int const _bits = 8;
public:
	Fixed();
	Fixed(Fixed const& copy);
	Fixed& operator=(Fixed &fix);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
	
};
