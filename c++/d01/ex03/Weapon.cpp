/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:30:22 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/14 13:52:52 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

Weapon::Weapon()
{}

Weapon::Weapon(std::string type) : _type(type)
{
}

Weapon::~Weapon()
{}

const std::string &Weapon::getType(void)
{
	return (_type);
}

void Weapon::setType(std::string wpn)
{
	_type = wpn;
}