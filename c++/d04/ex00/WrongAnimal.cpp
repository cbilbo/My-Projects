/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:36:37 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/13 16:47:22 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <string>
#include <iostream>

WrongAnimal::WrongAnimal(const std::string &name) : _type(name)
{
	std::cout << "WrongAnimal " << _type << " created." << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &copy) : _type(copy._type)
{
	std::cout << "WrongAnimal " << _type << "was copied by " << copy._type  << '.' << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal " << _type << " deleted." << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &src)
{
	if (this == &src)
		return (*this);
	this->_type = src._type;
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << _type << " says : \"???\"" << std::endl;
}

void	WrongAnimal::setType(const std::string &name)
{
	_type = name;
}

std::string WrongAnimal::getType(void) const
{
	return (_type);
}