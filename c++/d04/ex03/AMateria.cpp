/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 22:08:25 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/15 17:28:10 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <string>
#include <iostream>

AMateria::AMateria(std::string const &type) : _type(type)
{
}

AMateria::AMateria(const AMateria &copy) : _type(copy._type)
{
}

AMateria &AMateria::operator=(const AMateria &copy)
{
	if (this != &copy)
		_type = copy._type;
	return (*this);
}
std::string const &AMateria::getType() const
{
	return (_type);
}

void	AMateria::use(ICharacter &target)
{
	std::cout << _type << " used on " << target.GetName() << std::endl;
}