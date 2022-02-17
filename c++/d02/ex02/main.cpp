/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:26:50 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/09 21:03:30 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main()
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a++ << std::endl;
	std::cout << --a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	a = 10;
	std::cout << a << std::endl;
	a = a + 5;
	std::cout << a << std::endl;
	a = a - 3;
	std::cout << a << std::endl;
	Fixed d(2);
	a = a * d;
	std::cout << a << std::endl;
	a = a / d;
	std::cout << a << std::endl;
	if (a > b)
		std::cout << "true" << std::endl;
	if (a < b)
		std::cout << "true" << std::endl;
	if (a >= b)
		std::cout << "true" << std::endl;
	if (a <= b)
		std::cout << "true" << std::endl;
	if (a == b)
		std::cout << "true" << std::endl;
	if (a != b)
		std::cout << "true" << std::endl;
	return 0;
}