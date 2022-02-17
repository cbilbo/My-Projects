/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:30:38 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/03 20:42:51 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name) , _wpn(weapon)
{
}

HumanA::~HumanA()
{}

void HumanA::attack()
{
	std::cout << _name << " attacks with his " << _wpn.getType() << std::endl;
}