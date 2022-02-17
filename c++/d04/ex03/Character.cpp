/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:10:41 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/15 17:29:33 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <string>
#include <iostream>

Character::Character(std::string const &target) : _target(target)
{
	for (int i = 0; i < 4; ++i)
		_m[i] = 0;
}

Character::~Character()
{
	for (int i = 0; i < 4; ++i)
	{
		if (_m[i] != 0)
		{
			delete _m[i];
			_m[i] = 0;
		}
	}
}

Character::Character(Character const &copy)
{
	_target = copy._target;
	for (int i = 0; i < 4; ++i)
	{
		_m[i] = copy._m[i]->clone();
	}
}

Character &Character::operator=(Character const &copy)
{
	if (this != &copy)
	{
		_target = copy._target;
		for (int i = 0; i < 4; ++i)
			_m[i] = copy._m[i]->clone();
	}
	return (*this);
}

std::string const &Character::GetName() const
{
	return (_target);
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_m[i] == 0)
		{
			_m[i] = m->clone();
			std::cout << "Materia " << _m[i]->getType() << " puts in inventory by index " << i << std::endl;
			break ;
		}
		if (i == 3)
			std::cout << "Inventory is full\n";
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		delete _m[idx];
		_m[idx] = 0;
	}
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4)
	{
		if (_m[idx] != 0)
			_m[idx]->use(target);
	}
}