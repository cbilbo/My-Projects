/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:30:32 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/03 20:53:27 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name)
{
}

HumanB::~HumanB()
{}

void	HumanB::setWeapon(Weapon &weapon)
{
	_wpn = &weapon;
}

void HumanB::attack()
{
	std::cout << _name << " attacks with his " << _wpn->getType() << std::endl;
}