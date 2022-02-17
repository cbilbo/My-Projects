/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:05:19 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/13 20:45:42 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <string>
#include <iostream>

Animal::Animal(const std::string &name) : _type(name)
{
	std::cout << "Animal " << _type << " created." << std::endl;
}

Animal::Animal(const Animal &copy) : _type(copy._type)
{
	std::cout << "Animal " << _type << "was copied by " << copy._type  << '.' << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal " << _type << " deleted." << std::endl;
}

Animal	&Animal::operator=(Animal const &src)
{
	if (this == &src)
		return (*this);
	this->_type = src._type;
	std::cout << _type << " animal was assigned by " << src._type << std::endl;
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << _type << " says : \"???\"" << std::endl;
}

void	Animal::setType(const std::string &name)
{
	_type = name;
}

std::string Animal::getType(void) const
{
	return (_type);
}