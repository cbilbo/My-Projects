/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:43:22 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/15 17:26:59 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <string>
#include <iostream>

Ice::Ice(const std::string &name) : AMateria(name)
{
}

Ice::Ice(const Ice &copy) : AMateria(copy._type)
{
}

Ice	&Ice::operator=(const Ice &copy)
{
	if (this != &copy)
		_type = copy._type;
	return (*this);
}

Ice::~Ice()
{
}

Ice *Ice::clone() const
{
	Ice	*res = new Ice(*this);
	return (res);
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.GetName() << " *"<< std::endl;
}