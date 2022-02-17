/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:55:53 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/28 21:18:41 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <string>
#include <iostream>

std::string const DiamondTrap::_default_name = "DiamondTrap";
const int DiamondTrap::_default_hp = FragTrap::getDefHp();
const int DiamondTrap::_default_ep = ScavTrap::getDefEp();
const int DiamondTrap::_default_dmg = FragTrap::getDefDmg();

DiamondTrap::DiamondTrap(std::string const &name, const int &hp, const int &ep, const int &dmg) : ClapTrap(name + "_clap_name", hp, ep, dmg), ScavTrap(), FragTrap(), _name(name)
{
	std::cout << _name << ": DiamondTrap constructor called!" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy)
{
	_name = copy.ClapTrap::getName();
	_hp = copy.ClapTrap::getHp();
	_ep = copy.ClapTrap::getEp();
	_dmg = copy.ClapTrap::getDmg();
			  std::cout
		  << "DiamondTrap: Copy constructor called!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap: Destructor called!" << std::endl;
}

void DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::WhoAmI()
{
	std::cout << "ClapTrap name is " << ClapTrap::_name << "\nDiamond name is " << _name << std::endl;
}



DiamondTrap &DiamondTrap::operator=(DiamondTrap const &trap)
{
	if (this == &trap)
		return (*this);
	ClapTrap::setName(trap.ClapTrap::getName());
	ClapTrap::setHp(trap.ClapTrap::getHp());
	ClapTrap::setEp(trap.ClapTrap::getEp());
	ClapTrap::setDmg(trap.ClapTrap::getDmg());
	return (*this);
}

std::string	DiamondTrap::getName(void) const
{
	return (_name);
}

int DiamondTrap::getDefHp(void)
{
	return (_default_hp);
}

int DiamondTrap::getDefEp(void)
{
	return (_default_ep);
}

int DiamondTrap::getDefDmg(void)
{
	return (_default_dmg);
}

void DiamondTrap::printInfo() const
{
	std::cout << "Name: " << _name << "\nHitpoints: " << _hp << "\nEnergy points " << _ep << "\nDamage points: " << _dmg << std::endl;
}