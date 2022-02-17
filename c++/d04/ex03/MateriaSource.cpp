/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:54:52 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/15 17:12:00 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
	{
		_m[i] = 0;
	}
}
MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
	{
		if (_m[i] != 0)
		{
			if (_m[i]->getType() == "ice")
				delete dynamic_cast<Ice*>(_m[i]);
			else if (_m[i]->getType() == "cure")
				delete dynamic_cast<Cure*>(_m[i]);
		}
	}
}

void	MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_m[i] == 0)
		{
			_m[i] = m->clone();
			std::cout << "Materia " << _m[i]->getType() << " learned!\n";
			return ;
		}
		if (i == 3)
			std::cout << "Can't learn more!\n";
	}
	
}
AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_m[i]->getType() == type)
		{
			AMateria *materia = _m[i];
			return (materia);
		}
	}
	return (0);
}