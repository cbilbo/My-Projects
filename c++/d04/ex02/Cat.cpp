/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:25:10 by cbilbo            #+#    #+#             */
/*   Updated: 2021/12/13 20:01:39 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

Cat::Cat(const std::string &name) : Animal(name)
{
	std::cout << "Cat " << _type << " created." << std::endl;
	_brain = new Brain(_type);
}
Cat::Cat(const Cat &copy) : Animal(copy._type)
{
	_brain = new Brain(*copy._brain);
	std::cout << "Cat " << _type << "was copied by " << copy._type  << '.' << std::endl;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat " << _type << " deleted." << std::endl;
}

Cat	&Cat::operator=(Cat const &src)
{
	if (this == &src)
		return (*this);
	this->_type = src._type;
	this->_brain = new Brain(*src._brain);
	std::cout << "Cat was assigned\n";
	std::cout << _type << " cat was assigned by " << src._type << std::endl;
	return (*this);
}
void	Cat::makeSound(void) const
{
	std::cout << _type << " says : Meow!" << std::endl;
}

void	Cat::setIdeaToBrain(const std::string &idea, int pos)
{
	_brain->setIdea(idea, pos);
}

std::string Cat::getIdeaFromBrain(int pos) const
{
	return (_brain->getIdea(pos));
}