/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:27:04 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/10 18:23:02 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap: Default constructor called!" << std::endl;	
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap: Named constructor called!" << std::endl;	
}

ScavTrap::ScavTrap(ScavTrap const &copy)
{
	_name = copy.getName();
	_hp = copy.getHp();
	_ep = copy.getEp();
	_dmg = copy.getDmg();
	std::cout << "ScavTrap: Copy constructor called!" << std::endl;	
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: Destructor called!" << std::endl;	
}

void	ScavTrap::attack(std::string const &target)
{
	if (getHp() < 1)
	{
		std::cout << "ScavTrap " << getName() << " has no hitpoints! Please repair it" << std::endl;
	}
	switch (getEp())
	{
	case (0):
		std::cout << "ScavTrap " << getName() << " was deactivated due to no energy points left!" << std::endl;
		break ;
	default:
		std::cout << "ScavTrap " << getName() << " attack " << target << ", causing " << getDmg() << " points of damage!" << std::endl;
		setEp(getEp() - 1);
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << getName() << " have enterred in Gate keeper mode." << std::endl;
}

ScavTrap	&ScavTrap::operator = (ScavTrap const &trap)
{
	if (this == &trap)
		return (*this);
	setName(trap.getName());
	setHp(trap.getHp());
	setEp(trap.getEp());
	setDmg(trap.getDmg());
	return (*this);
}