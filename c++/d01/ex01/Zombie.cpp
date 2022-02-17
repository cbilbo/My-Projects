/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:20:43 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/14 13:53:14 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie(void)
{}

Zombie::Zombie(std::string str) : _name(str)
{
}

void	Zombie::setName(std::string name)
{
	_name = name;
}

Zombie::~Zombie(void)
{
	std::cout << _name << " died!" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
