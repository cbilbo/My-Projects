/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:44:23 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/21 22:05:57 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <iostream>

int main()
{
	Data *d = new Data("WOW, it's impossible");
	uintptr_t ui;
	ui = serialize(d);
	Data *r;
	r = deserialize(ui);
	std::cout << "d: " << d->_str << std::endl << "r: " << r->_str << std::endl;
	delete d;
	return (0);
}