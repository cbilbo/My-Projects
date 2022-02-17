/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:21:20 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/13 15:56:01 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>
#include <string>

std::string const FragTrap::_default_name = "FragTrap";
const int FragTrap::_default_hp = 100;
const int FragTrap::_default_ep = 100;
const int FragTrap::_default_dmg = 30;

FragTrap::FragTrap(std::string const &name, const int &hp, const int &ep, const int &dmg) : ClapTrap(name, hp, ep, dmg)
{
	std::cout << _name << ": FragTrap constructor called!" << std::endl;
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

void FragTrap::attack(std::string const &target)
{
	if (getHp() < 1)
	{
		std::cout << "<FragTrap> " << getName() << " has no hitpoints! Please repair it" << std::endl;
	}
	switch (getEp())
	{
	case (0):
		std::cout << "<FragTrap> " << getName() << " was deactivated due to no energy points left!" << std::endl;
		break;
	default:
		std::cout << "<FragTrap> " << getName() << " attack " << target << ", causing " << getDmg() << " points of damage!" << std::endl;
		setEp(getEp() - 1);
	}
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "1.First\n2.Second\n3.Third\n4.Fourth\n5.Fifth" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &trap)
{
	if (this == &trap)
		return (*this);
	setName(trap.getName());
	setHp(trap.getHp());
	setEp(trap.getEp());
	setDmg(trap.getDmg());
	return (*this);
}

int FragTrap::getDefHp(void)
{
	return (_default_hp);
}

int FragTrap::getDefEp(void)
{
	return (_default_ep);
}

int FragTrap::getDefDmg(void)
{
	return (_default_dmg);
}