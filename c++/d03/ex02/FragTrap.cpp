/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:21:20 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/10 18:42:32 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap()
{
	std::cout << "FragTrap: Default constructor called!" << std::endl;	
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap: Named constructor called!" << std::endl;	
}

FragTrap::FragTrap(FragTrap const &copy)
{
	_name = copy.getName();
	_hp = copy.getHp();
	_ep = copy.getEp();
	_dmg = copy.getDmg();
	std::cout << "FragTrap: Copy constructor called!" << std::endl;	
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: Destructor called!" << std::endl;	
}

void	FragTrap::attack(std::string const &target)
{
	if (getHp() < 1)
	{
		std::cout << "FragTrap " << getName() << " has no hitpoints! Please repair it" << std::endl;
	}
	switch (getEp())
	{
	case (0):
		std::cout << "FragTrap " << getName() << " was deactivated due to no energy points left!" << std::endl;
		break ;
	default:
		std::cout << "FragTrap " << getName() << " attack " << target << ", causing " << getDmg() << " points of damage!" << std::endl;
		setEp(getEp() - 1);
	}
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "1.First\n2.Second\n3.Third\n4.Fourth\n5.Fifth" << std::endl;
}

FragTrap	&FragTrap::operator = (FragTrap const &trap)
{
	if (this == &trap)
		return (*this);
	setName(trap.getName());
	setHp(trap.getHp());
	setEp(trap.getEp());
	setDmg(trap.getDmg());
	return (*this);
}