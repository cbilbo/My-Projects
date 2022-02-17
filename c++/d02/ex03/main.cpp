/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:26:50 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/09 21:06:49 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

//http://cyber-code.ru/tochka_v_treugolnike/ векторный метод

int main(void)
{
	Point a(-4, -2);
	Point b(-10, 0);
	Point c(-5, -5);
	Point p(2, 2);
	if (bsp(a, b, c, p))
		std::cout << "ok" << std::endl;
	else
		std::cout << "not ok" << std::endl; 
	Point q(0.5, 0.5);
	Point w(10.4, 0.1);
	Point e(5.2, 5.2);
	Point r(2.1, 2.1);
	if (bsp(q, w, e, r))
		std::cout << "ok" << std::endl;
	else
		std::cout << "not ok" << std::endl; 
	return (0);
}