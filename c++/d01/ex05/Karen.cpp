/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:27:12 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/09 20:29:38 by cbilbo           ###   ########.fr       */
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
	void	(Karen::*lvl[4])() = \
				{&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};
	std::string	lvl_name[4] = \
			{"debug", "info", "warning", "error"};
	for (int i = 0; i < 4; ++i)
	{
		switch (lvl_name[i].compare(level))
		{
		case (0):
			(this->*lvl[i])();
			return ;
		}
	}
	std::cout << "I don't understand!" << std::endl;
}