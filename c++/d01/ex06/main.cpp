/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:26:56 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/09 20:33:50 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"
#include <string>
#include <iostream>

int main(int ac, char **av)
{
	switch (ac)
	{
	case (2):
		break ;
	default:
		std::cout << "I don't understand" << std::endl;
		return (0);
	}
	Karen karen;
	std::string mes = av[1];
	karen.complain(mes);
	return (0); 
}