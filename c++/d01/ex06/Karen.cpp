/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:27:03 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/09 20:37:00 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"
#include <string>
#include <iostream>

Karen::Karen()
{};

Karen::~Karen()
{};

void Karen::debug(void)
{
	std::cout << "DEBUG" << std::endl;
}

void Karen::info(void)
{
	std::cout << "INFO" << std::endl;
}

void Karen::warning(void)
{
	std::cout << "WARNING" << std::endl;
}

void Karen::error(void)
{
	std::cout << "ERROR" << std::endl;
}

void Karen::complain(std::string level)
{
	int	lvl = 0;
	std::string lvls[4] = \
			{"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; ++i)
	{
		switch (level.compare(lvls[i]))
		{
		case (0):
			lvl = i + 1;
			break ;
		default:
			continue ;
		}
	}
	switch (lvl)
	{
	case 1:
		debug();
	case 2:
		info();
	case 3:
		warning();
	case 4:
		error();
		break ;
	default:
		std::cout << "I don't understand!" << std::endl;
	}
}