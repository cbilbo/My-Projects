/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:44:08 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/21 21:25:49 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"
#include <string>
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: wrong number of parameters\n";
		return (1);
	}
	try
	{
		convert a(av[1]);
		std::cout << a;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	
	return (0);
}