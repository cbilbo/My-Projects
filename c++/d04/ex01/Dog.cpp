/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:22:21 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/13 20:38:27 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

Dog::Dog(const std::string &name) : Animal(name)
{
	std::cout << "Dog " << _type << " created." << std::endl;
	_brain = new Brain(_type);
}
Dog::Dog(const Dog &copy) : Animal(copy._type)
{
	_brain = new Brain(*copy._brain);
	std::cout << "Dog " << _type << "was copied by " << copy._type  << '.' << std::endl;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog " << _type << " deleted." << std::endl;
}

Dog	&Dog::operator=(Dog const &src)
{
	if (this == &src)
		return (*this);
	this->_brain = new Brain(*src._brain);
	this->_type = src._type;
	std::cout << _type << "dog was assigned by " << src._type << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << _type << " says : Wuff!" << std::endl;
}

void	Dog::setIdeaToBrain(const std::string &idea, int pos)
{
	_brain->setIdea(idea, pos);
}

std::string Dog::getIdeaFromBrain(int pos) const
{
	return (_brain->getIdea(pos));
}