/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:46:46 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/14 17:37:10 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <string>
#include <iostream>

Cure::Cure(const std::string &name) : AMateria(name)
{
}

Cure::Cure(const Cure &copy) : AMateria(copy._type)
{
}

Cure	&Cure::operator=(const Cure &copy)
{
	if (this != &copy)
		_type = copy._type;
	return (*this);
}

Cure::~Cure()
{
}

Cure *Cure::clone() const
{
	Cure	*res = new Cure(*this);
	return (res);
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.GetName() << "'s wounds *" << std::endl;
}