/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:06:46 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/10 17:43:37 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

ClapTrap::ClapTrap() : _name("Default"), _hp(10), _ep(10), _dmg(0)
{
	std::cout << "Default constructor called!" << std::endl;	
}

ClapTrap::ClapTrap(std::string const &name) : _name(name), _hp(10), _ep(10), _dmg(0)
{
	std::cout << "Named constructor called!" << std::endl;	
}

ClapTrap::ClapTrap(std::string const &name, const int &hp, const int &ep, const int &dmg) :\
		_name(name), _hp(hp), _ep(ep), _dmg(dmg)
{
	std::cout << "Full constructor called!" << std::endl;	
}

ClapTrap::ClapTrap(ClapTrap const &copy) : _name(copy.getName()), _hp(copy.getHp()), _ep(copy.getEp()), _dmg(copy.getDmg())
{
	std::cout << "Copy constructor called!" << std::endl;	
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called!" << std::endl;	
}

std::string	ClapTrap::getName(void) const
{
	return (_name);
}

void		ClapTrap::setName(std::string const &name)
{
	_name = name;
}

int			ClapTrap::getHp(void) const
{
	return (_hp);
}

void		ClapTrap::setHp(const int &hp)
{
	_hp = hp;
}

int			ClapTrap::getEp(void) const
{
	return (_ep);
}

void		ClapTrap::setEp(const int &ep)
{
	_ep = ep;
}

int			ClapTrap::getDmg(void) const
{
	return (_dmg);
}

void		ClapTrap::setDmg(const int &dmg)
{
	_dmg = dmg;
}

void	ClapTrap::attack(std::string const &target)
{
	if (getHp() < 1)
	{
		std::cout << "ClapTrap " << getName() << " has no hitpoints! Please repair it" << std::endl;
		return ;
	}
	switch (getEp())
	{
	case (0):
		std::cout << "ClapTrap " << getName() << " was deactivated due to no energy points left!" << std::endl;
		break ;
	default:
		std::cout << "ClapTrap " << getName() << " attack " << target << ", causing " << getDmg() << " points of damage!" << std::endl;
		setEp(getEp() - 1);
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	setHp(getHp() - amount);
	if (getHp() < 0)
		setHp(0);
	std::cout << "ClapTrap " << getName() << " is taken " << amount << " damage. " << getHp() << " hitpoints left!" << std::endl;
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	setHp(amount);
	std::cout << "ClapTrap " << getName() << " was repaired by " << amount << " hitpoints!" << std::endl;
}

ClapTrap	&ClapTrap::operator = (ClapTrap const &trap)
{
	if (this == &trap)
		return (*this);
	setName(trap.getName());
	setHp(trap.getHp());
	setEp(trap.getEp());
	setDmg(trap.getDmg());
	return (*this);
}